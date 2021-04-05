#include <GameManager.h>
#include <thread>
#include <iostream>

GameManager::GameManager()
{

}


void GameManager::start_new_game(int capacity, std::string gameName)
{
    this->games.push_back(Game(capacity, gameName));

    /*
    auto new_game = []() {
        Game game = Game();
        game.start();
    };
     */

//    threads.push_back(std::thread(&new_game));
}

std::vector<GameListItem> GameManager::get_game_list()
{
    std::vector<GameListItem> gameList = std::vector<GameListItem>();

    for (auto &game : this->games)
    {
        gameList.push_back(GameListItem(game.nbPlayers, game.capacity, game.name.c_str()));
    }
    return gameList;
}
