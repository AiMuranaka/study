#include "mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget* window = new QWidget;
    QHBoxLayout *layout1 = new QHBoxLayout;             //  1行目のボタン列のための水平レイアウト
    QPushButton *b1 = new QPushButton("button&1");      //  ボタン1～3 widgit オブジェクト生成
    QPushButton *b2 = new QPushButton("button&2");
    QPushButton *b3 = new QPushButton("button&3");
    layout1->addWidget(b1);                             //  ボタン1～3 widgit オブジェクトをレイアウトに追加
    layout1->addWidget(b2);
    layout1->addWidget(b3);
    QHBoxLayout *layout2 = new QHBoxLayout;             //  2行目のボタン列のための水平レイアウト
    QPushButton *b4 = new QPushButton("button&4");      //  ボタン4～6 widgit オブジェクト生成
    QPushButton *b5 = new QPushButton("button&5");
    layout2->addWidget(b4);                             //  ボタン4～6 widgit オブジェクトをレイアウトに追加
    layout2->addWidget(b5);
    QVBoxLayout *layout = new QVBoxLayout;              //  レイアウトを縦に並べる垂直レイアウト
    layout->addLayout(layout1);                         //  1, 2 行目を垂直レイアウトに追加
    layout->addLayout(layout2);
    window->setLayout(layout);                          //  垂直レイアウトをメインウィンドウに setLayout()
    window->show();
    return app.exec();

}
