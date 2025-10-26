#include <iostream>
#include <string>
using namespace std;

class Page
{
public:
    string url;
    Page* next;
    Page* prev;
    Page(string url)
    {
        this->url = url;
        next = nullptr;
        prev = nullptr;
    }
};

void deleteForwardPages(Page* node)
{
    Page* p = node;
    while (p)
    {
        Page* t = p->next;
        delete p;
        p = t;
    }
}

void visit(Page*& current, const string& url)
{
    if (!current)
    {
        current = new Page(url);
        return;
    }
    if (current->next)
    {
        deleteForwardPages(current->next);
        current->next = nullptr;
    }
    Page* np = new Page(url);
    current->next = np;
    np->prev = current;
    current = np;
}

void goBack(Page*& current)
{
    if (current && current->prev) current = current->prev;
}

void goForward(Page*& current)
{
    if (current && current->next) current = current->next;
}

void displayCurrent(Page* current)
{
    if (current) cout << "Current Page: " << current->url << "\n";
    else cout << "No pages open\n";
}

void displayHistory(Page* current)
{
    if (!current)
    {
        cout << "History: (empty)\n";
        return;
    }
    Page* head = current;
    while (head->prev) head = head->prev;
    cout << "History: ";
    Page* p = head;
    bool first = true;
    while (p)
    {
        if (!first) cout << " <-> ";
        cout << p->url;
        first = false;
        p = p->next;
    }
    cout << "\n(Current Page: " << current->url << ")\n";
}

void cleanup(Page* current)
{
    if (!current) return;
    while (current->prev) current = current->prev;
    deleteForwardPages(current);
}

string trim(const string& s)
{
    size_t i = 0, j = s.size();
    while (i < j && isspace((unsigned char)s[i])) ++i;
    while (j > i && isspace((unsigned char)s[j-1])) --j;
    return s.substr(i, j - i);
}

int main()
{
    Page* current = nullptr;
    string line;
    while (true)
    {
        cout << "> ";
        if (!getline(cin, line)) break;
        line = trim(line);
        if (line.empty()) continue;
        if (line == "exit" || line == "quit") break;
        if (line.rfind("visit(", 0) == 0 && line.back() == ')')
        {
            string inside = line.substr(6, line.size() - 7);
            if (!inside.empty() && inside.front() == '"' && inside.back() == '"')
                inside = inside.substr(1, inside.size() - 2);
            visit(current, trim(inside));
            continue;
        }
        if (line.rfind("visit ", 0) == 0)
        {
            string url = trim(line.substr(6));
            visit(current, url);
            continue;
        }
        if (line == "back() " || line == "back()") { goBack(current); continue; }
        if (line == "back") { goBack(current); continue; }
        if (line == "forward() " || line == "forward()") { goForward(current); continue; }
        if (line == "forward") { goForward(current); continue; }
        if (line == "displayCurrent() " || line == "displayCurrent()") { displayCurrent(current); continue; }
        if (line == "displayCurrent") { displayCurrent(current); continue; }
        if (line == "displayHistory() " || line == "displayHistory()") { displayHistory(current); continue; }
        if (line == "displayHistory") { displayHistory(current); continue; }
        cout << "Unknown command\n";
    }
    cleanup(current);
    return 0;
}
// ...existing code...