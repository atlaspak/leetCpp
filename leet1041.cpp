enum class Direction
{
    North,
    East,
    South,
    West
};

Direction& operator++(Direction& d)
{
    switch(d)
    {
        case Direction::North:      return d = Direction::East;
        case Direction::East:       return d = Direction::South;
        case Direction::South:      return d = Direction::West;
        case Direction::West:       return d = Direction::North;
    }
}

Direction& operator--(Direction& d)
{
    switch(d)
    {
        case Direction::North:      return d = Direction::West;
        case Direction::East:       return d = Direction::North;
        case Direction::South:      return d = Direction::East;
        case Direction::West:       return d = Direction::South;
    }
}

class Solution {
public:
    bool isRobotBounded(string instructions) 
    {
        int x = 0, y = 0;
        Direction direction = Direction::North;
        if(instructions.size() == 0)
        {
            return true;
        }
        for(int j = 0; j < 4; j++)
        for(int i = 0; i < instructions.size(); i++)
        {
            if(instructions[i] == 'G')
            {
                switch(direction)
                {
                    case Direction::North:
                        y++;
                        break;
                    case Direction::East:
                        x++;
                        break;
                    case Direction::South:
                        y--;
                        break;
                    case Direction::West:
                        x--;
                        break;
                }
            }
            else if(instructions[i] == 'L')
            {
                --direction;
            }
            else if(instructions[i] == 'R')
            {
                ++direction;
            }
        }
        if(x == 0 && y == 0)
        {
            return true;
        }
        return false;   
    }
};
