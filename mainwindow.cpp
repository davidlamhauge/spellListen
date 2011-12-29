#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui>
#include <QFile>
#include <QFileInfo>
#include <QDir>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    ord = new Phonon::MediaObject(this);
    mAudioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(ord, mAudioOutput);
    ui->labLetters->setVisible(true);
    ui->btnLetters->setIcon(QIcon("icons/notext-icon.png"));
    // figure out how many hooray.png's there are...
    hoorays = 0;
    helpIndicator = "+";
    QDir dir("icons/");
    dir.setFilter(QDir::Files | QDir::Hidden);
    dir.setSorting(QDir::Size | QDir::Reversed);
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); i++){
        if (list.at(i).fileName().endsWith("hooray.png"))
            hoorays += 1;
    }
    userName = "";
    createActions();
    initVars();
    setReady(false);
    ui->leInput->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initVars(){
    numWords = 0, correctWords = 0, counter = 0;
    userName = "" , userFileName = "", statusTip = "";
}

void MainWindow::initScreen(){
    setReady(false);
    ui->btnWordFile->setEnabled(true);
    ui->btnScrWordFile->setEnabled(true);
    ui->labWordCount->setText("");
    ui->labCorrect->setText("");
    ui->labComment->setText("");
}

void MainWindow::setReady(bool b){
    QPalette p = ui->leInput->palette();
    p.setColor(QPalette::Base, QColor(255, 255, 255));
    if (b == false){
        ui->btnHear->setDisabled(true);
        ui->btnLetters->setDisabled(true);
        ui->btnNext->setDisabled(true);
        ui->leInput->setDisabled(true);
    }else{
        ui->btnHear->setEnabled(true);
        ui->btnLetters->setEnabled(true);
        ui->btnNext->setEnabled(true);
        ui->leInput->setEnabled(true);
    }
    ui->leInput->setFocus();
}

void MainWindow::createActions(){
    // if EXIT button is pressed, program exits
    connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(continueOK()));
    // if HEAR button is pressed, wavefile is played,
    connect(ui->btnHear, SIGNAL(clicked()),this,SLOT(hearWord()));
    // if WORDFILE button is pressed, a new wordfile is loaded
    connect(ui->btnWordFile,SIGNAL(clicked()),this,SLOT(scrNo()));
    connect(ui->btnScrWordFile, SIGNAL(clicked()), this, SLOT(scrYes()));
    // if SEELETTERS button is pressed, labLetters is set visible/invisible
    connect(ui->btnLetters, SIGNAL(clicked()),this, SLOT(seeLetters()));

    connect(ui->btnNext, SIGNAL(clicked()), this, SLOT(dummyNext()));
    connect(ui->btnHelp, SIGNAL(clicked()), this, SLOT(showHelp()));
    connect(ui->leInput, SIGNAL(textChanged(QString)),this, SLOT(updateText()));

}

void MainWindow::dummyNext(){
    if (counter == spell.count()){
        disconnect(ui->leInput,SIGNAL(textChanged(QString)),this, SLOT(updateText()));
        ui->leInput->setText(spell[counter - 1]);
        connect(ui->leInput, SIGNAL(textChanged(QString)),this, SLOT(updateText()));
    }else{
        nextWord(counter);
    }
}

void MainWindow::nextWord(int i){
    if (counter < spell.count()){
        numWords += 1;
        QString s, s1;
        ui->labWordCount->setText(s.setNum(numWords) + tr(" of ") + s1.setNum(spell.count()));
        ui->labCorrect->setText(s.setNum(correctWords) + tr(" of ") + s1.setNum(counter));
        ui->labComment->setText(comm[counter]);
        // the word, scrambled word and soundprefix initialises
        realWord = spell[i];
        ui->leInput->clear();
        ui->leInput->setMaxLength(realWord.length());

        scrambledWord = scramble(realWord);
        ui->labLetters->clear();
        ui->labLetters->setText(scrambledWord);

        soundPrefix = spell[i];

        counter += 1;
        QPalette p = ui->leInput->palette();
        p.setColor(QPalette::Base, QColor(255,255,255));
        hearWord();
    }
}

void MainWindow::updateText(){
    QString str = ui->leInput->text();
    savework();
    QString in = scrambledWord;
    QPalette p = ui->leInput->palette();
    if (str != realWord.left(str.length()))
        p.setColor(QPalette::Base, QColor(250,180,180));
    else
        p.setColor(QPalette::Base, QColor(180,250,180));
    if (str.length() == 0)
        p.setColor(QPalette::Base, QColor(255,255,255));
    ui->leInput->setPalette(p);

    if (str.length() > 0){
        QChar c;
        for (int i = 0;i < str.count(); i++){
            c = str.at(i);
            int ix = in.indexOf(c);
            if (ix > -1){
                in.remove(ix,1);
            }
        }
        ui->labLetters->setText(in);
    }else
        ui->labLetters->setText(scrambledWord);
    if (str == realWord){
        p.setColor(QPalette::Base, QColor(255,255,255));
        correctWords += 1;
        QString s, s2;
        ui->labCorrect->setText(s.setNum(correctWords) + tr(" of ") + s2.setNum(counter));

        int tal;
        tal = rand() % hoorays;
        QPixmap pixmap("icons/" + s.setNum(tal + 1) + "_hooray.png");

        ui->labHooray->setPixmap(pixmap);

        if (numWords < spell.count()){
//            nextWord(counter);
        }else{
            // TODO a beautiful FINISHED dialog, and then...
            disconnect(ui->leInput,SIGNAL(textChanged(QString)),this, SLOT(updateText()));
            ui->leInput->clear();
            connect(ui->leInput, SIGNAL(textChanged(QString)),this, SLOT(updateText()));
            showResult();
            initScreen();
        }
    }
}

QString MainWindow::scramble(QString s){
    QChar tmp;
    int tal;
    for (int i = 1; i < 30; i++){
        tal = rand() % s.length();
        tmp = s.at(tal);
        s.remove(tal,1);
        s.append(tmp);
    }
    return s;
}

QStringList MainWindow::scrambleList(QStringList sl){
    QString tmp = "";
    int tal;
    for (int i = 1; i < 30; i++){
        tal = rand() % sl.length();
        tmp = sl.at(tal);
        sl.removeAt(tal);
        sl.append(tmp);
        tmp = comm.at(tal);
        comm.removeAt(tal);
        comm.append(tmp);
    }
    return sl;
}

/*
  The three next functions do the same, and ends with openWordFile().
  If the connect goes through openScrWordFile(), it scrambles
  the sequence of the words first
*/
void MainWindow::scrYes(){
    scrList = true;
    openWordfile();
}

void MainWindow::scrNo(){
    scrList = false;
    openWordfile();
}

void MainWindow::openWordfile(){
    // first we get username. If username exists it is put in the Dialog
    bool ok;
    QString un = userName;
    userName = "";
    QString text = QInputDialog::getText(this, tr("Write name"),
                                             tr("Your name:"), QLineEdit::Normal,
                                             un, &ok);
    if (ok && !text.isEmpty()){
        setReady(true);
        userName = text;
        ui->labUser->setText(tr("Name: "));
        ui->labUserName->setText(userName);
        QTime time = QTime::currentTime();
        QString sTime = time.toString("HH:mm:ss");
        userFileName = userName + "_" + sTime;
    }
    // get ready for the new word file - IF username exists!
    if (userName.length() > 0){
        statusTip = "";
        spell.clear();
        QString tmp_s, filename;
        filename = getFileName();
        QStringList sl;
        sl = getStringList(filename);
        if (sl.count() > 0){
            for (int i = 0; i < sl.count(); i++){
                tmp_s = sl[i];
                sl[i] = tmp_s;
            }
            if (scrList)
                spell = scrambleList(sl);
            else
                spell = sl;
            // HERE starts the spelling quest...
            updateText();
            ui->labCorrect->setText("");
            ui->labWordCount->setText("");
            QPixmap pixmap("icons/tux.png");
            ui->labHooray->setPixmap(pixmap);
            ui->labInfo->setText(statusTip);
            numWords = 0;
            correctWords = 0;
            counter = 0;
            ui->btnWordFile->setEnabled(false);
            ui->btnScrWordFile->setEnabled(false);
            nextWord(counter);
        }else{
            spell.clear();
            QMessageBox msgBox;
            msgBox.setText(tr("The word-list is empty!"));
            msgBox.exec();
            setReady(false);
        }
    }else{
        QMessageBox msgBox;
        msgBox.setText(tr("Please write username..."));
        msgBox.exec();
    }
}

void MainWindow::hearWord(){
    if (spell.count() > 0){
        QString s = filePath + spell[counter-1].toLower() + ".wav";
        ord->setCurrentSource(s);
        ord->play();
    }
}

void MainWindow::seeLetters(){
    if (ui->labLetters->isVisible()){
        // Hides Letters
        helpIndicator = "-";
        ui->labLetters->setVisible(false);
        ui->btnLetters->setIcon(QIcon("icons/text-icon.png"));
    }else{
        // Shows letters
        helpIndicator = "+";
        ui->labLetters->setVisible(true);
        ui->btnLetters->setIcon(QIcon("icons/notext-icon.png"));
    }
}

void MainWindow::continueOK(){
    QMessageBox mb;
    mb.setWindowTitle(tr("Exit Yes/No..."));
    mb.setText(tr("Do you wish to exit?"));
    mb.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    mb.setDefaultButton(QMessageBox::Cancel);
    int ret = mb.exec();
    if (ret ==QMessageBox::Yes)
        MainWindow::close();
}

QString MainWindow::getFileName(){
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),"", tr("SpellListen wordlist-files (*.stav)"));
    QFileInfo fi(filename);
    //filepath is used as pre-prefix for sound-files
    filePath = fi.absolutePath() + "/";
    return filename;
}

/*
  Returns a list of strings.
  The original file has one word per line.
  If the line contains a "#", it means that the word before the "#" is the word to spell,
  and the word after the "#" is the soundfile-prefix.
*/

QStringList MainWindow::getStringList(QString s){
    comm.clear();
    QFile fil(s);
    QStringList sl;
    fil.open(QIODevice::ReadOnly);
    while (!fil.atEnd()){
        s = fil.readLine().trimmed();
        if (s.length() > 0){
            // line is a general comment on the words in the file
            if (s.startsWith("#")){
                statusTip = s.right(s.length() - 1);
            // line is a word + a specific comment to this word
            }else if(s.contains('#')){
                QStringList tmp = s.split('#');
                sl.append(tmp[0]);
                comm.append(tmp[1]);
            // line is a word, without a comment
            }else{
                sl.append(s);
                comm.append("");
            }
        }
    }
    fil.close();
    return sl;
}

void MainWindow::savework(){
    // we put ERROR message in 's' - just in case
    QString s;
    QString str = ui->leInput->text();
    if (str != realWord.left(str.length()))
        s = tr(" * Error!");
    else
        s = "";
    QFile file(filePath + userFileName + ".txt");
    file.open(QFile::WriteOnly | QFile::Append);
    QTextStream qout(&file);
    qout << helpIndicator << ui->leInput->text() << " # " << realWord << s << "\n";
    file.close();
}

void MainWindow::showHelp(){
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("SpellListen - Help"));
    msgBox.setText(tr("F2  : Open word list in sequence\n"
                      "F3  : Open word list out of sequence\n"
                      "F4  : Hear the word you are going to spell\n"
                      "F5  : Show/Hide letters to use in word\n"
                      "F8  : Fetch next word in wordfile\n"
                      "F10 : Exit program"));
    msgBox.exec();
}

void MainWindow::showResult(){
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Congratulations %1").arg(userName));
    msgBox.setText(tr("You finished you task...\n\n"
                      "Correct spelled:\n"
                      "%1 of %2 words.\n\n"
                      "Satisfied?").arg(correctWords).arg(numWords));
    msgBox.exec();
}


