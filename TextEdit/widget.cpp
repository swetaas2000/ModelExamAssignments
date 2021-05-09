#include "widget.h"
#include<QTextEdit>
#include<QLabel>
#include<QPushButton>
#include<QDebug>
#include<QFont>
#include<QColorDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
      QFont labelFont("Times",20,QFont::Bold);
        QLabel *mLabel=new QLabel("This is My Sentence",this);
          mLabel->setFont(labelFont);
            mLabel->move(100,25);
            QPalette label;

            label.setColor(QPalette::Window,Qt::yellow);

            label.setColor(QPalette::WindowText,Qt::red);

            mLabel->setAutoFillBackground(true);

            mLabel->setPalette(label);

            QTextEdit *text=new QTextEdit(this);

            text->move(70,55);

            connect(text,&QTextEdit::textChanged,[=](){

            qDebug()<<"Text Changed"; });


            QPushButton *cut=new QPushButton("cut",this);
          //  QPushButton.setColor(QPalette::Window,Qt::yellow);
           cut->setStyleSheet("* { background-color: rgb(255,125,100) }");

            cut->setMinimumSize(50,25);

            cut->move(10,250);

            connect(cut,&QPushButton::clicked,[=](){

             text->cut(); });


            QPushButton *copy=new QPushButton("copy",this);
             copy->setStyleSheet("* { background-color: blue }");

            copy->setMinimumSize(50,25);

            copy->move(110,250);

            connect(copy,&QPushButton::clicked,[=](){

             text->copy(); });

            QPushButton *paste=new QPushButton("paste",this);
             paste->setStyleSheet("* { background-color: green }");

            paste->setMinimumSize(50,25);

            paste->move(210,250);

            connect(paste,&QPushButton::clicked,[=](){

             text->paste(); });


            QPushButton *undo=new QPushButton("undo",this);
            undo->setStyleSheet("* { background-color: red }");
            undo->setMinimumSize(50,25);

            undo->move(10,280);

            connect(undo,&QPushButton::clicked,[=](){

             text->undo(); });


            QPushButton *redo=new QPushButton("redo",this);
             redo->setStyleSheet("* { background-color: yellow }");

            redo->setMinimumSize(50,25);

            redo->move(110,280);

            connect(redo,&QPushButton::clicked,[=](){

             text->redo(); });







            QPushButton *html=new QPushButton("HTML",this);
             html->setStyleSheet("* { background-color: orange}");

            html->setMinimumSize(100,25);

            html->move(120,310);

            connect(html,&QPushButton::clicked,[=](){

             text->setHtml("<h1>Title</h1><p>Three districts:</br> <ul><li>X</li><li>Y</li><li>Z</li></ul></p>");  });
}

Widget::~Widget()
{
}

