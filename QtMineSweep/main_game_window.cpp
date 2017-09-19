#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include <QMessageBox>
#include "main_game_window.h"
#include "ui_maingamewindow.h"
#include "game_model.h"

// ---------全局变量------------ //
const int blockSize = 20;
const int offsetX = 5; // 横向边距
const int offsetY = 5; // 纵向边距
const int spaceY = 70; // 上方空白用于绘制记分板
// ------------------------------//

MainGameWindow::MainGameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainGameWindow)
{
    ui->setupUi(this);
    // 创建计时数字标签
    timeLabel = new QLabel(this);
    // 关联信号槽
    connect(ui->actionStart, SIGNAL(triggered(bool)), this, SLOT(onStartGameClicked()));
    connect(ui->actionBasic, SIGNAL(triggered(bool)), this, SLOT(onLevelChooseClicked()));
    connect(ui->actionMedium, SIGNAL(triggered(bool)), this, SLOT(onLevelChooseClicked()));
    connect(ui->actionHard, SIGNAL(triggered(bool)), this, SLOT(onLevelChooseClicked()));
    connect(ui->actionQuit, SIGNAL(triggered(bool)), this, SLOT(onQuitClicked()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));


    // 创建游戏初始化游戏，设置好参数，默认是中级,启动计时器
    // 定义窗口大小(必须放在游戏创建之后后面，该函数设置后大小不可变动，窗口强制重绘)
    game = new GameModel;
    game->createGame();
    setFixedSize(game->mCol * blockSize + offsetX * 2, game->mRow * blockSize + offsetY * 2 + spaceY);
    timeLabel->setGeometry(game->mCol * blockSize + offsetX * 2 - 80, spaceY / 2, 80, 20);
    timeLabel->setText("Time: " + QString::number(game->timerSeconds) + " s");
    timer->start(1000);
}

MainGameWindow::~MainGameWindow()
{
    // 清理
    delete game;
    game = NULL;
    delete ui;
}

void MainGameWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap bmpBlocks(":/res/blocks.bmp");
    QPixmap bmpFaces(":/res/faces.bmp");
    QPixmap bmpFrame(":/res/frame.bmp");
    QPixmap bmpNumber(":/res/timenumber.bmp");

    // 绘制笑脸
    switch(game->gameState)
    {
    case OVER:
        painter.drawPixmap((game->mCol * blockSize + offsetX * 2) / 2 - 12, spaceY / 2, bmpFaces, 0 * 24, 0, 24, 24); // 24是笑脸的边长,锚点在左上，因为工具栏占了些，所以看起来不再中间
        break;
    case PLAYING:
        painter.drawPixmap((game->mCol * blockSize + offsetX * 2) / 2 - 12, spaceY / 2, bmpFaces, 1 * 24, 0, 24, 24);
        break;
    case WIN:
        painter.drawPixmap((game->mCol * blockSize + offsetX * 2) / 2 - 12, spaceY / 2, bmpFaces, 2 * 24, 0, 24, 24);
        break;
    default:
        painter.drawPixmap((game->mCol * blockSize + offsetX * 2) / 2 - 12, spaceY / 2, bmpFaces, 1 * 24, 0, 24, 24);
        break;
    }

    // 绘制剩余雷数
    int n = game->curMineNumber;
    int posX = (game->mCol * blockSize + offsetX * 2) / 2 - 50; // 最后一位数字的横坐标
    if(n <= 0) // 如果雷数为0或者减到0以下，单独绘制
    {
        painter.drawPixmap(posX, spaceY / 2, bmpNumber, n * 20, 0, 20, 28); // 20是数字的宽，28是高
    }
    while(n > 0) // 如果是多位数
    {
        painter.drawPixmap(posX - 20, spaceY / 2, bmpNumber, n % 10 * 20, 0, 20, 28); // 每次从后面绘制一位
        n /= 10;
        posX -= 20;
    }

    // 绘制雷区
    for(int i = 0; i < game->mRow; i++)
    {
        for(int j = 0; j < game->mCol; j++)
        {
            switch(game->gameMap[i][j].curState)
            {
            // 根据不同的方块状态绘制，算出在bmp中的偏移量
            case UN_DIG:
                painter.drawPixmap(j * blockSize + offsetX, i * blockSize + offsetY + spaceY , bmpBlocks, blockSize * 10, 0, blockSize, blockSize);
                break;
            case DIGGED:
                painter.drawPixmap(j * blockSize + offsetX, i * blockSize + offsetY + spaceY, bmpBlocks, blockSize * game->gameMap[i][j].valueFlag, 0, blockSize, blockSize);
                break;
            case MARKED:
                painter.drawPixmap(j * blockSize + offsetX, i * blockSize + offsetY + spaceY, bmpBlocks, blockSize * 11, 0, blockSize, blockSize);
                break;
            case BOMB:
                painter.drawPixmap(j * blockSize + offsetX, i * blockSize + offsetY + spaceY, bmpBlocks, blockSize * 9, 0, blockSize, blockSize);
                break;
            case WRONG_BOMB:
                if(game->gameState == PLAYING || game->gameState == FAULT)
                {
                    // 如果还在游戏中就显示旗子
                    painter.drawPixmap(j * blockSize + offsetX, i * blockSize + offsetY + spaceY, bmpBlocks, blockSize * 11, 0, blockSize, blockSize);
                }
                else if(game->gameState == OVER)
                {
                    // 如果游戏已经结束，就显示标错了
                    painter.drawPixmap(j * blockSize + offsetX, i * blockSize + offsetY + spaceY, bmpBlocks, blockSize * 12, 0, blockSize, blockSize);
                }
                break;
            default:
                break;
            }
        }
    }
    // 处理游戏状态
    handleGameState(game);
}

void MainGameWindow::handleGameState(GameModel *game)
{
    if(game->gameState == OVER)
    {
        timer->stop();
        qDebug() << "you lose!";
    }
    else if(game->gameState == WIN)
    {
        timer->stop();
        qDebug() << "you win!";
//        // 可以选择弹窗告知游戏胜利成绩
//        QMessageBox::information(this, "win!", "your time: " + QString::number(game->timerSeconds) + " s");
//        game->gameState = PLAYING; // 赶紧要改回正常状态，不然那个弹窗消失不了
    }
}

void MainGameWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->y() < spaceY + offsetY)
    {
        int x = event->x();
        int y = event->y();
        // 此时判断是否点击笑脸
        if(x >= (game->mCol * blockSize + offsetX * 2) / 2 - 12
        && x <= (game->mCol * blockSize + offsetX * 2) / 2 + 12
        && y >= spaceY / 2
        && y <= spaceY / 2 + 24)
        {
            game->restartGame(); // 重玩
            timer->start(1000);
            timeLabel->setText("Time: " + QString::number(game->timerSeconds) + " s"); // 每次重玩都将计时显示为0s
            update();
        }
    }
    else if(game->gameState != OVER && game->gameState != WIN)
    {
        // 游戏没输或没赢才接受点击
        // 此时判断点击的是哪个方块
        // 获得点击坐标
        int px = event->x() - offsetX;
        int py = event->y() - offsetY - spaceY;
        // 换算成方格索引
        int row = py / blockSize;
        int col = px / blockSize;
        // 根据不同情况响应
        switch(event->button())
        {
        case Qt::LeftButton:
            game->digMine(row, col);
            update(); // 每次点击都要重绘
            break;
        case Qt::RightButton:
            game->markMine(row, col);
            update();
            break;
        default:
            break;
        }
    }

}

void MainGameWindow::onStartGameClicked()
{
    qDebug()<<"game started";
    game->restartGame(); // 重新开始
    timeLabel->setText("Time: " + QString::number(game->timerSeconds) + " s");
    timer->start(1000);
    update();
}

void MainGameWindow::onLevelChooseClicked()
{
    QAction *actionSender = (QAction *)dynamic_cast<QAction *>(sender());
    if(actionSender == ui->actionBasic)
    {
        qDebug() << "basic";
        // 先设置游戏模型
        game->createGame(8, 10, 15, BASIC);
    }
    else if(actionSender == ui->actionMedium)
    {
        qDebug() << "medium";
        game->createGame(15, 20, 50, MEDIUM);
    }
    else if(actionSender == ui->actionHard)
    {
        qDebug() << "hard";
        game->createGame(20, 30, 100, HARD);
    }
    // 重新计时
    timer->start(1000);
    // 再刷新UI，窗口大小改变会强制重绘
    timeLabel->setText("Time: " + QString::number(game->timerSeconds) + " s");
    timeLabel->setGeometry(game->mCol * blockSize + offsetX * 2 - 80, spaceY / 2, 80, 20);
    setFixedSize(game->mCol * blockSize + offsetX * 2, game->mRow * blockSize + offsetY * 2 + spaceY);
}

void MainGameWindow::updateTimer()
{
    // 计时器计时
    game->timerSeconds++;
    timeLabel->setText("Time: " + QString::number(game->timerSeconds) + " s");
    qDebug() << game->timerSeconds;
}

void MainGameWindow::onQuitClicked()
{
    // 退出
    QCoreApplication::quit();
}
