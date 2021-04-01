#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int  node;
    char character;
};

int nNodes, nEdges;
int startNode;

vector<vector<Edge>> edges;

bool dfa( int node, string word, int index )
{
    if( index == word.size() ) {
        return true;
    }

    // for (int i = 0; i < size(edges[node]); ++i) {
    //     edge = edges[node][i];
    // }
    for( auto edge : edges[node] )  // for each
    {
        if( edge.character == word[index] ) {
            return dfa( edge.node, word, index + 1 );
        }
    }

    return false;
}

void ReadDFA()
{
    cout << "Number of nodes: ";
    cin >> nNodes;
    edges.reserve( nNodes );  // reserve memory for nNodes
    cout << "Start node is: ";
    cin >> startNode;

    cout << "Number of transitions is: ";
    cin >> nEdges;

    int  x, y;
    char character;
    for( int i = 0; i < nEdges; ++i ) {
        cout << "transition #" << i + 1 << ": ";
        cin >> x;
        cin >> y;
        cin >> character;
        edges[x].push_back( { y, character } );
    }
}

void AcceptWords()
{
    int i;
    cout << "The word is: ";
    string word;
    cin >> word;


    /// we check if the word is accepted by DFA
    if( dfa( startNode, word, 0 ) ) {
        cout << "Fine, I accept this word!\n";
    }
    else {
        cout << "Sorry, I can't accept this word...\n";
    }

    cout << "Do you want another word? - 1\n";
    cout << "Bye bye? - 0\n";

    int optiune;
    cin >> optiune;
    if( optiune == 1 ) {
        AcceptWords();
    }
}

int main()
{
    ReadDFA();
    AcceptWords();
}
