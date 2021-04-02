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
vector<int>          transitions;

// dfa returns true if word is accepted
bool dfa( int node, string word, int index )
{
    transitions.push_back( node );

    if( index == word.size() ) {
        if( edges[node].size() == 0 ) {
            return true;
        }

        return false;
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
        cout << "The transition is: ";
        for( int i = 0; i < transitions.size(); ++i ) {
            cout << transitions[i] << " ";
        }
        cout << '\n';

        transitions.clear();  // clear transitions for the next word
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
