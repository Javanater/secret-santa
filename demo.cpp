#include <using_convenience.hpp>

int main()
{
    vector<string> people {"Abbey", "Bobby", "Charlie", "Doyle", "Eric", "Frank"};
    vector<set<string>> groups {
        {"Abbey", "Bobby"},
        {"Charlie", "Doyle"},
        {"Eric", "Frank"},
    };

    auto are_in_group = [&](string const& a, string const& b)
    {
        for (auto group : groups)
            if (group.count(a) && group.count(b))
                return true;

        return false;
    };

    auto has_inter_group_santas = [&]
    {
        auto a = --people.end();
        
        for (auto b = people.begin(); b != people.end(); ++b)
        {
            if (are_in_group(*a, *b))
                return true;

            a = b;
        }

        return false;
    };

    random_device rd;
    mt19937 g(rd());

    do
        shuffle(people.begin(), people.end(), g);
    while (has_inter_group_santas());

    auto a = --people.end();
        
    for (auto b = people.begin(); b != people.end(); ++b)
    {
        ofstream ofs(*a + "'s secret santa.txt");
        ofs << *a << " is " << *b << "'s secret santa!" << endl;
        a = b;
    }

    return 0;
}
