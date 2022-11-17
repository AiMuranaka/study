#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class Databases : public QObject
{
    Q_OBJECT

public:
    Databases();
    ~Databases();

private slots:
    void test_case1();

};

Databases::Databases()
{

}

Databases::~Databases()
{

}

void Databases::test_case1()
{
    QTest::addColumn<bool>("bool");
    QTest::newRow("local 1") << false;
    QTest::newRow("local 2") << true;

    QSKIP("skipping all");
}

QTEST_MAIN(Databases)

#include "tst_databases.moc"
