#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>

std::list<std::pair<int, int>> getAdjacentTargets(std::vector<std::vector<char>> &visited, std::pair<int, int> target)
{
    std::list<std::pair<int, int>> retValue = std::list<std::pair<int, int>>();
    const int MAX_X = visited.size();
    const int MAX_Y = visited[0].size();
    if (target.first > 0 && visited[target.first - 1][target.second] != '#')
    {
        retValue.push_back(std::pair<int, int>(target.first - 1, target.second));
    }
    if (target.first < MAX_X - 1 && visited[target.first + 1][target.second] != '#')
    {
        retValue.push_back(std::pair<int, int>(target.first + 1, target.second));
    }
    if (target.second > 0 && visited[target.first][target.second - 1] != '#')
    {
        retValue.push_back(std::pair<int, int>(target.first, target.second - 1));
    }
    if (target.second < MAX_Y - 1 && visited[target.first][target.second + 1] != '#')
    {
        retValue.push_back(std::pair<int, int>(target.first, target.second + 1));
    }
    return retValue;
}

struct CarryoverInfo
{
    std::pair<int, int> visit;
    std::list<std::pair<int, int>> path;
};

std::pair<bool, std::list<std::pair<int, int>>> connected(std::vector<std::vector<char>> &graph, std::pair<int, int> &caperucita, std::pair<int, int> &lobo)
{
    std::queue<CarryoverInfo> visit = std::queue<CarryoverInfo>();
    std::vector<std::vector<char>> visited = std::vector<std::vector<char>>(graph);
    CarryoverInfo startOnLobo = {
        visit : std::pair<int, int>(lobo),
        path : std::list<std::pair<int, int>>()
    };

    visit.push(startOnLobo);

    while (visit.size() > 0)
    {
        CarryoverInfo &target = visit.front();
        std::list<std::pair<int, int>> adjacentsToVisit = getAdjacentTargets(visited, target.visit);
        std::for_each(adjacentsToVisit.begin(),
                      adjacentsToVisit.end(),
                      [&visited, &visit, &target](std::pair<int, int> &element2Visit)
                      {
                          visited[element2Visit.first][element2Visit.second] = '#';
                          std::list<std::pair<int, int>> currentHistory = std::list<std::pair<int, int>>(target.path);
                          currentHistory.push_back(target.visit);
                          CarryoverInfo info = {
                              visit : element2Visit,
                              path : currentHistory
                          };
                          visit.push(info);
                      });
        if (visited[caperucita.first][caperucita.second] == '#')
        {
            target.path.push_back(target.visit);
            //Remove the lobo
            target.path.pop_front();
            //Remove the nearest to the caperucita if possible
            if (target.path.size() > 0)
                target.path.pop_back();

            std::for_each(target.path.begin(),
                          target.path.end(),
                          [](std::pair<int, int> step)
                          { std::cout << "(" << step.first << ":" << step.second << ") -> "; });
            std::cout << std::endl;
            return std::pair<bool, std::list<std::pair<int, int>>>(true, target.path);
        }
        visit.pop();
    }
    return std::pair<bool, std::list<std::pair<int, int>>>(false, std::list<std::pair<int, int>>());
}

std::string mincut(std::vector<std::vector<char>> &graph, std::pair<int, int> &caperucita, std::pair<int, int> &lobo)
{
    int retValue = 0;
    bool iterating = true;
    std::for_each(graph.begin(), graph.end(), [](std::vector<char> &line)
                  {
                      std::for_each(line.begin(), line.end(), [](char &c)
                                    { std::cout << c << " "; });
                      std::cout << std::endl;
                  });

    do
    {
        std::pair<bool, std::list<std::pair<int, int>>> result = connected(graph, caperucita, lobo);
        if (result.first)
        {
            //Ojo que no podemos poner trampas en las cuatro casillas adyacentes
            if (result.second.size() == 0)
            {
                retValue = -1;
                iterating = false;
            }
            else
            {
                std::for_each(result.second.begin(),
                              result.second.end(), [&graph](std::pair<int, int> pathnode)
                              { graph[pathnode.first][pathnode.second] = '#'; });
                std::for_each(graph.begin(), graph.end(), [](std::vector<char> &line)
                              {
                                  std::for_each(line.begin(), line.end(), [](char &c)
                                                { std::cout << c << " "; });
                                  std::cout << std::endl;
                              });
                retValue++;
            }
        }
        else
        {
            iterating = false;
        }
    } while (iterating);

    return retValue < 0 ? "IMPOSIBLE" : std::to_string(retValue);
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int times, N, M;
    std::cin >> times;
    for (; times > 0; times--)
    {
        std::cin >> N >> M;
        std::vector<std::vector<char>> graph = std::vector<std::vector<char>>(N);
        std::pair<int, int> caperucita;
        std::pair<int, int> lobo;
        for (int x = 0; x < N; x++)
        {
            std::vector<char> line = std::vector<char>(M);
            for (int y = 0; y < M; y++)
            {
                std::cin >> line[y];
                if (line[y] == 'C')
                    caperucita = std::pair<int, int>(x, y);
                else if (line[y] == 'L')
                    lobo = std::pair<int, int>(x, y);
            }
            graph[x] = line;
        }
        std::cout << mincut(graph, caperucita, lobo) << std::endl;
        graph.clear();
    }
}