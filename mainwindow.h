#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <phonon/AudioOutput>
#include <phonon/MediaObject>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Phonon::MediaObject* ord;
    Phonon::AudioOutput* mAudioOutput;
    QStringList spell, swapped;
    QStringList comm;       // list of comments
    QString statusTip;      // tip at the bottom of the screen
    bool scrList;           // scramble list yes/no
    int numWords, correctWords;
    int counter;            // the count in nextWord
    QString filePath;
    QString soundPrefix;

    QString helpIndicator;  // "+" for helping letters, "-" for none
    QString realWord;
    QString scrambledWord;
    int hoorays;            // number of hooray-icons

    QString userName, userFileName ;

public slots:
    void hearWord();        // plays wavefile connected to word
    void seeLetters();      // show or hide letters to use + change icon
    void scrYes();          // open a wordfile with scrambled sequence
    void scrNo();           // open a wordlist with unscrambled sequence
    void continueOK();      // continue or EXIT?
    void updateText();      // updates text and changes bg-color
    void dummyNext();       // calls nextWord with counter as parameter
    void showHelp();        // shows the HELP MessageBox

private:
    Ui::MainWindow *ui;
    void initScreen();      // initiates the screen wuth figures, images...
    void createActions();   // initiates all connected SIGNALs and SLOTs
    QString getFileName();  // gets FILENAME for new word-string-list
    QStringList getStringList(QString s);   // gets stringlist fom file s
    void main_spell();      // main function that walks through the word-list
    QString scramble(QString);  // returns scrambled word - an anagram
    QStringList scrambleList(QStringList sl); // returns scrambled StringList
    void openWordfile();    // opens wordfile and prepares wordlist
    void nextWord(int);     // goes to word number "int" in the stringlist
    void savework();        // save all keypresses + words to spell
    void initVars();        // initiales variables
    void setReady(bool);    // sets lineinput etc Enabled or Disabled
    void showResult();      // Shows your users result when finished

};

#endif // MAINWINDOW_H
