#include "AI.h"

bool AI::MoveBlackPawn(Cell(&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn(&pawns)[PAWN_SIZE])
{
    while (true)
    {
        numberPawn = rand() % PAWN_SIZE;
        if (pawns[numberPawn].GetIsPlace() == false)
        {
            if (firstCondition && secondCondition)
            {
                lastCell = false;
                firstCondition = false;
                secondCondition = false;
                cellX++;
                cellY++;
            }
            if (DirectionPawn(field, pawns))
            {
                if (!GetLastCell())
                {
                    if (pawns[numberPawn].sprite.getPosition() == field[GAMEFIELD_SIZE - GetCellX()][GAMEFIELD_SIZE - GetCellY()].sprite.getPosition())
                    {
                        lastCell = true;
                        pawns[numberPawn].SetIsPlace();
                        firstCondition = false;
                        secondCondition = false;
                    }
                }
                if (GetLastCell())
                {
                    if (pawns[numberPawn].sprite.getPosition() == field[GAMEFIELD_SIZE - GetCellX()][GAMEFIELD_SIZE - (GetCellY() + 1)].sprite.getPosition())
                    {
                        pawns[numberPawn].SetIsPlace();
                        firstCondition = true;
                    }
                    if ((pawns[numberPawn].sprite.getPosition() == field[GAMEFIELD_SIZE - (GetCellX() + 1)][GAMEFIELD_SIZE - GetCellY()].sprite.getPosition()) && secondCondition == false)
                    {
                        pawns[numberPawn].SetIsPlace();
                        secondCondition = true;
                    }
                }
                return true;
            }
        }
    }
    return false;
}

bool AI::DirectionPawn(Cell(&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn(&pawns)[PAWN_SIZE])
{
    bool main_action = rand() % 2;
    if (main_action)
    {
        if (MoveDown(field, pawns))
        {
            return true;
        }
        else
        {
            if (MoveRight(field, pawns))
            {
                return true;
            }
        }
    }
    else
    {
        if (MoveRight(field, pawns))
        {
            return true;
        }
        else
        {
            if (MoveDown(field, pawns))
            {
                return true;
            }
        }
    }
    bool confirmation = rand() % 2;
    if (confirmation)
    {
        if (MoveUp(field, pawns))
        {
            return true;
        }
    }
    else
    {
        if (MoveLeft(field, pawns))
        {
            return true;
        }
    }
    return false;
}

bool AI::MoveRight(Cell(&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn(&pawns)[PAWN_SIZE])
{
    if ((pawns[GetNumberPawn()].GetCurrentCell().x + 1) < GAMEFIELD_SIZE)
    {
        if (field[pawns[GetNumberPawn()].GetCurrentCell().x + 1][pawns[GetNumberPawn()].GetCurrentCell().y].GetStatusCell() == 0)
        {
            field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y].SetStatusCell();
            pawns[GetNumberPawn()].sprite.setPosition(field[pawns[GetNumberPawn()].GetCurrentCell().x + 1][pawns[GetNumberPawn()].GetCurrentCell().y].GetSprite().getPosition());
            pawns[GetNumberPawn()].SetCurrentCell(sf::Vector2i(pawns[GetNumberPawn()].GetCurrentCell().x + 1, pawns[GetNumberPawn()].GetCurrentCell().y));
            field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y].SetStatusCell(pawns[GetNumberPawn()].GetStatus());
            return true;
        }
    }
    return false;
}

bool AI::MoveDown(Cell(&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn(&pawns)[PAWN_SIZE])
{
    if ((pawns[GetNumberPawn()].GetCurrentCell().y + 1) < GAMEFIELD_SIZE)
    {
        if (field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y + 1].GetStatusCell() == 0)
        {
            field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y].SetStatusCell();
            pawns[GetNumberPawn()].sprite.setPosition(field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y + 1].GetSprite().getPosition());
            pawns[GetNumberPawn()].SetCurrentCell(sf::Vector2i(pawns[GetNumberPawn()].GetCurrentCell().x, pawns[GetNumberPawn()].GetCurrentCell().y + 1));
            field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y].SetStatusCell(pawns[GetNumberPawn()].GetStatus());
            return true;
        }
    }
    return false;
}

bool AI::MoveLeft(Cell(&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn(&pawns)[PAWN_SIZE])
{
    if ((pawns[GetNumberPawn()].GetCurrentCell().x - 1) >= 0)
    {
        if (field[pawns[GetNumberPawn()].GetCurrentCell().x - 1][pawns[GetNumberPawn()].GetCurrentCell().y].GetStatusCell() == 0)
        {
            field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y].SetStatusCell();
            pawns[GetNumberPawn()].sprite.setPosition(field[pawns[GetNumberPawn()].GetCurrentCell().x - 1][pawns[GetNumberPawn()].GetCurrentCell().y].GetSprite().getPosition());
            pawns[GetNumberPawn()].SetCurrentCell(sf::Vector2i(pawns[GetNumberPawn()].GetCurrentCell().x - 1, pawns[GetNumberPawn()].GetCurrentCell().y));
            field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y].SetStatusCell(pawns[GetNumberPawn()].GetStatus());
            return true;
        }
    }
    return false;
}

bool AI::MoveUp(Cell(&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn(&pawns)[PAWN_SIZE])
{
    if ((pawns[GetNumberPawn()].GetCurrentCell().y - 1) >= 0)
    {
        if (field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y - 1].GetStatusCell() == 0)
        {
            field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y].SetStatusCell();
            pawns[GetNumberPawn()].sprite.setPosition(field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y - 1].GetSprite().getPosition());
            pawns[GetNumberPawn()].SetCurrentCell(sf::Vector2i(pawns[GetNumberPawn()].GetCurrentCell().x, pawns[GetNumberPawn()].GetCurrentCell().y - 1));
            field[pawns[GetNumberPawn()].GetCurrentCell().x][pawns[GetNumberPawn()].GetCurrentCell().y].SetStatusCell(pawns[GetNumberPawn()].GetStatus());
            return true;
        }
    }
    return false;
}
