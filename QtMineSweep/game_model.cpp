#include <time.h>
#include <stdlib.h>
#include "game_model.h"

GameModel::GameModel()
    : mRow(kRow),
      mCol(kCol),
      totalMineNumber(kMineCount),
      timerSeconds(kTime),
      gameState(PLAYING)
{
    // 在构造函数里面不做具体初始化，因为构造函数的调用时间不确定
}

GameModel::~GameModel()
{

}

void GameModel::createGame(int row, int col, int mineCount, GameLevel level)
{
    // 先清空已经有的游戏地图
    gameMap.clear();
    // 设置成员变量
    mRow = row;
    mCol = col;
    totalMineNumber = mineCount;
    curMineNumber = mineCount;
    gameState = PLAYING;
    gameLevel = level;
    timerSeconds = 0;

    // 初始化雷方块
    for(int i = 0; i < mRow; i++)
    {
        //添加每行的block
        std::vector<MineBlock> lineBlocks;
        for(int j = 0; j < mCol; j++)
        {
            MineBlock mineBlock;
            mineBlock.curState = UN_DIG; // 默认都是未挖掘
            mineBlock.valueFlag = 0; // 默认都是0
            lineBlocks.push_back(mineBlock);
        }
        gameMap.push_back(lineBlocks);
    }

    // 随机布雷
    srand((unsigned int)time(0));
    int k = totalMineNumber;
    while(k > 0)
    {
        // 埋雷并防止重叠
        int pRow = rand() % mRow;
        int pCol = rand() % mCol;
        if(gameMap[pRow][pCol].valueFlag != -1)
        {
             gameMap[pRow][pCol].valueFlag = -1;
             k--; // 如果原来就有雷重新循环
        }
    }

    // 计算雷周围的方块数字
    for(int i = 0; i < mRow; i++)
    {
        for(int j = 0; j < mCol; j++)
        {
            // 周围八个方块（排除自己，在地图范围内）的数字根据雷的数目叠加
            // y为行偏移量，x为列偏移量
            // 前提条件是本方块不是雷
            if(gameMap[i][j].valueFlag != -1)
            {
                for(int y = -1; y <= 1; y++)
                {
                    for(int x = -1; x <= 1; x++)
                    {
                        if(i + y >= 0
                        && i + y < mRow
                        && j + x >= 0
                        && j + x < mCol
                        && gameMap[i + y][j + x].valueFlag == -1
                        && !(x == 0 && y == 0))
                        {
                            // 方块数字加1
                            gameMap[i][j].valueFlag++;
                        }
                    }
                }
            }
        }
    }
}

void GameModel::restartGame()
{
    createGame(mRow, mCol, totalMineNumber, gameLevel);
}

void GameModel::digMine(int m, int n)
{
    // 正常方块且没有被翻开过，标记为已挖
    if(gameMap[m][n].valueFlag > 0
     && gameMap[m][n].curState == UN_DIG)
    {
        gameMap[m][n].curState = DIGGED;
    }

    // 遇到空白块（数字0）就递归挖雷，如果踩雷就爆掉,游戏结束
    if(gameMap[m][n].valueFlag == 0
     && gameMap[m][n].curState == UN_DIG)
    {
        gameMap[m][n].curState = DIGGED;
        for(int y = -1; y <= 1; y++)
        {
            for(int x = -1; x <= 1; x++)
            {
                if(m + y >= 0
                && m + y < mRow
                && n + x >= 0
                && n + x < mCol
                && !(x == 0 && y == 0))
                {
                    digMine(m + y, n + x);
                }
            }
        }
    }

    // 踩雷了
    if(gameMap[m][n].valueFlag == -1)
    {
        gameState = OVER;
        gameMap[m][n].curState = BOMB;
    }

    // 检查游戏输赢,并作调整
    checkGame();
}

void GameModel::markMine(int m, int n)
{
    // 如果标记错了，就记为错误标记，在ui层游戏结束时做绘制区分
    // 注意这里有个逻辑，如果一个方块标记两次会回到未挖掘的状态
    if(gameMap[m][n].curState == UN_DIG)
    {
        if(gameMap[m][n].valueFlag == -1)
        {
            gameMap[m][n].curState = MARKED;
        }
        else
        {
            gameState = FAULT;
            gameMap[m][n].curState = WRONG_BOMB;
        }
        curMineNumber--; // 挖对了雷就减1
    }
    else if(gameMap[m][n].curState == MARKED || gameMap[m][n].curState == WRONG_BOMB)
    {
        gameMap[m][n].curState = UN_DIG;
        gameState = PLAYING;
        curMineNumber++; // 雷数加回来
    }
    // 检查游戏输赢,并作调整
    checkGame();
}

void GameModel::checkGame()
{
    // 游戏结束，显示所有雷
    if(gameState == OVER)
    {
        // 输了就显示所有的雷以及标错的雷
        for(int i = 0; i < mRow; i++)
        {
            for(int j = 0; j < mCol; j++)
            {
                if(gameMap[i][j].valueFlag == -1)
                {
                    gameMap[i][j].curState = BOMB;
                }
            }
        }
        return;
    }
    // 如果雷排完了，且所有方块都挖出或者标记
    if(gameState != FAULT)
    {
        for(int i = 0; i < mRow; i++)
        {
            for(int j = 0; j < mCol; j++)
            {
                if(gameMap[i][j].curState == UN_DIG)
                {
                    gameState = PLAYING;
                    return;
                }
            }
        }
        // 否则既没有错误标记游戏状态又不是输或者进行中，游戏就是赢了
        gameState = WIN;
    }
}
