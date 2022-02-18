#include "Game.h"

void Game::PlayGame()
{
    window.create(sf::VideoMode(GAMEFIELD_SIZE * CELL_SIZE, GAMEFIELD_SIZE * CELL_SIZE), "Rooks", sf::Style::Close | sf::Style::Titlebar);
    CreateGameField(window);
    CreatePawns(window);

    while (window.isOpen())
    {
        
        pixelPos = sf::Mouse::getPosition(window);
        pos = window.mapPixelToCoords(pixelPos);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Display(window);
        MovePawns();
        window.display();
        sf::Int32 frame_duration = clock.getElapsedTime().asMilliseconds();
        sf::Int32 time_to_sleep = int(1000.f / LIMIT_FPS) - frame_duration;
        if (time_to_sleep > 0)
        {
            sf::sleep(sf::milliseconds(time_to_sleep));
        }
        clock.restart();
    }
}

void Game::CreateGameField(sf::RenderWindow& window)
{
    int local_coordinate_x{ 0 }, local_coordinate_y{ 0 }, local_count_cell{ 0 };                                                                    // Count - счетчик для правильной окраски
    for (auto i{ 0 }; i < GAMEFIELD_SIZE; i++)
    {
        for (auto j{ 0 }; j < GAMEFIELD_SIZE; j++)
        {
            if (local_count_cell % 2 != 0)                                                                                                          
            {
                GameField[i][j].SetBrown();
            }
            GameField[i][j].SetPositionCell(sf::Vector2f(static_cast<float>(local_coordinate_x), static_cast<float>(local_coordinate_y)));
            GameField[i][j].SetStatusCell(0);
            GameField[i][j].sprite.setPosition(GameField[i][j].GetPositionCell());
            local_coordinate_x += CELL_SIZE;
            ++local_count_cell;
        }
        local_coordinate_y += CELL_SIZE;
        local_coordinate_x = 0;
        ++local_count_cell;
    }
}

void Game::Display(sf::RenderWindow& window)
{
    for (auto i{ 0 }; i < GAMEFIELD_SIZE; i++)
    {
        for (auto j{ 0 }; j < GAMEFIELD_SIZE; j++)
        {
            GameField[i][j].draw(window);
        }
    }
    for (auto i{ 0 }; i < PAWN_SIZE; i++)
    {
        WhitePawns[i].draw(window);
        BlackPawns[i].draw(window);
    }
    if (onText)
    {
        window.draw(text);
    }
}

void Game::CreatePawns(sf::RenderWindow& window)
{
    CreateBlackPawns(window);
    CreateWhitePawns(window);
}

void Game::CreateBlackPawns(sf::RenderWindow& window)
{
    int local_number_pawn { 0 };
    for (auto i{ 0 }; i < 3; i++)
    {
        for (auto j{ 0 }; j < 3; j++)
        {
            BlackPawns[local_number_pawn].sprite.move(GameField[i][j].GetPositionCell());
            GameField[i][j].SetStatusCell(BlackPawns[local_number_pawn].GetStatus());
            BlackPawns[local_number_pawn].SetCurrentPosition(sf::Vector2f(GameField[i][j].sprite.getPosition()));
            BlackPawns[local_number_pawn].SetCurrentCell(sf::Vector2i(i, j));
            local_number_pawn++;
        }
    }
}

void Game::CreateWhitePawns(sf::RenderWindow& window)
{
    int local_number_pawn{ 0 };
    for (int i { GAMEFIELD_SIZE - 3 }; i < GAMEFIELD_SIZE; i++)
    {
        for (int j{ GAMEFIELD_SIZE - 3 }; j < GAMEFIELD_SIZE; j++)
        {
            WhitePawns[local_number_pawn].sprite.setPosition(GameField[i][j].GetPositionCell());
            GameField[i][j].SetStatusCell(WhitePawns[local_number_pawn].GetStatus());
            WhitePawns[local_number_pawn].SetCurrentPosition(sf::Vector2f(GameField[i][j].sprite.getPosition()));
            WhitePawns[local_number_pawn].SetCurrentCell(sf::Vector2i(i, j));
            local_number_pawn++;
        }
    }
}

void Game::MoveBlackPawn()
{
    if (bot.MoveBlackPawn(GameField, BlackPawns))
    {
        WinCheck(GetStep());
        SetStep();
    } 
}

void Game::MoveWhitePawn()
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.key.code == sf::Mouse::Left)
        {
            for (auto i{ 0 }; i < PAWN_SIZE; i++)
            {
                if (WhitePawns[i].sprite.getGlobalBounds().contains(pos.x, pos.y))
                {
                    directionX = pos.x - WhitePawns[i].sprite.getPosition().x;
                    directionY = pos.y - WhitePawns[i].sprite.getPosition().y;
                    isMove = true;
                    SetNum(i);
                    break;
                }
            }
        }
    }
    if (event.type == sf::Event::MouseButtonReleased && GetNum() != NOT_SELECTED)
    {
        if (event.key.code == sf::Mouse::Left)
        {
            for (auto i{ 0 }; i < GAMEFIELD_SIZE; i++)
            {
                for (auto j{ 0 }; j < GAMEFIELD_SIZE; j++)
                {
                    if ((abs(WhitePawns[GetNum()].sprite.getPosition().x - GameField[i][j].sprite.getPosition().x) <= 50.f) &&
                        (abs(WhitePawns[GetNum()].sprite.getPosition().y - GameField[i][j].sprite.getPosition().y) <= 50.f))                    // если пешка над клеткой
                    {
                        if (WhitePawns[GetNum()].LegalMove(GameField, i, j))                                                                    // если движение не превышает 1 клетки                                                  
                        {
                            GameField[WhitePawns[GetNum()].GetCurrentCell().x][WhitePawns[GetNum()].GetCurrentCell().y].SetStatusCell();
                            WhitePawns[GetNum()].sprite.setPosition(GameField[i][j].sprite.getPosition());
                            WhitePawns[GetNum()].SetCurrentPosition(sf::Vector2f(GameField[i][j].sprite.getPosition()));
                            GameField[i][j].SetStatusCell(WhitePawns[GetNum()].GetStatus());
                            WhitePawns[GetNum()].SetCurrentCell(sf::Vector2i(i, j));
                            isMove = false;
                            SetNum(NOT_SELECTED);
                            WinCheck(GetStep());
                            SetStep();
                            break;
                        }
                        else
                        {
                            WhitePawns[GetNum()].sprite.setPosition(WhitePawns[GetNum()].GetCurrentPosition());
                            isMove = false;
                            SetNum(NOT_SELECTED);
                            break;
                        }
                    }
                }
            }
        }

    }
    if (isMove)
    {
        WhitePawns[GetNum()].sprite.setPosition(pos.x - (CELL_SIZE / 2), pos.y - (CELL_SIZE / 2));
        WhitePawns[GetNum()].SetVector(sf::Vector2f(pos.x - directionX, pos.y - directionY));
    }
}

void Game::WinCheck(const bool& b)
{
    if (b)
    {
        int local_number_cell{ 0 };
        for (auto i{ 0 }; i < 3; i++)
        {
            for (auto j{ 0 }; j < 3; j++)
            {
                if (GameField[i][j].GetStatusCell() == 1)
                {
                    local_number_cell++;
                }
            }
        }
        if (local_number_cell == 9)
        {
            PrintText("WIN");
            onText = true;
        }
    }
    else
    {
        int local_number_cell{ 0 };
        for (int i{ GAMEFIELD_SIZE - 3 }; i < GAMEFIELD_SIZE; i++)
        {
            for (int j{ GAMEFIELD_SIZE - 3 }; j < GAMEFIELD_SIZE; j++)
            {
                if (GameField[i][j].GetStatusCell() == 2)
                {
                    local_number_cell++;
                }
            }
        }
        if (local_number_cell == 9)
        {
            PrintText("LOSE");
            onText = true;
        }
    }
}

void Game::PrintText(const std::string& t)
{
    font.loadFromFile("Font\\font.ttf");
    text.setFont(font);
    text.setPosition(((GAMEFIELD_SIZE * CELL_SIZE) / 2), ((GAMEFIELD_SIZE * CELL_SIZE) / 2));
    text.setString(t);
    text.setCharacterSize(60);
    text.setStyle(sf::Text::Bold);
}

void Game::MovePawns()
{   
    (step) ? MoveWhitePawn() : MoveBlackPawn();
}