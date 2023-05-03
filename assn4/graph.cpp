#include "graph.h"
#include <fstream>
#include <iostream>
#include <string>
#define INF 2147483647 
using namespace std;


/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////
/*  Write your codes if you have additional functions  */

void enqueue(queue* q, int data) {
    node* temp;
    temp = new node;
    temp->data = data;
    temp->next = NULL;
    if (q->count == 0) {
        q->front = temp;
        q->rear = temp;
        q->count++;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
        q->count++;
    }
    return;
}

void dequeue(queue* q) {
    node* temp;
    if (q->count == 0) return;
    temp = q->front;
    q->front = q->front->next;
    q->count--;
    if (q->count == 0) {
        q->rear = q->front;
    }
    delete temp;
    return;
}

bool edgecmp(const edge& a, const edge& b) {
    return a.weight < b.weight;
}
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////


string Graph::DFS() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    string answer = "";
    bool* visited = new bool[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = false;
    }

    _DFS(answer, visited, 0);

    for (int i = 0; i < num_nodes; i++) {
        if (visited[i] == false) {
            //return "error";
            answer += "\n";
            _DFS(answer, visited, i);
        }
        else continue;
    }

    delete[] visited;
    return answer;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

void Graph::_DFS(string& answer, bool* visited, int c) {
    visited[c] = true;
    char ans = char(c + 65);
    answer += ans;
    answer += " ";

    for (int i = 0; i < num_nodes; i++) {
        if (adjmtrx[c][i] == 1 && visited[i] == false) {
            _DFS(answer, visited, i);
        }
    }
}

string Graph::BFS() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    string answer = "";
    bool* visited = new bool[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = false;
    }

    queue q;
    q.count = 0;
    q.front = NULL;
    q.rear = NULL;

    _BFS(answer, visited, q, 0);

    for (int i = 0; i < num_nodes; i++) {
        if (visited[i] == false) {
            //return "error";
            answer += "\n";
            _BFS(answer, visited, q, i);
        }
        else continue;
    }
    delete[] visited;
    return answer;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

void Graph::_BFS(string& answer, bool* visited, queue& q, int c) {
    visited[c] = true;
    char ans = char(c + 65);
    answer += ans;
    answer += " ";
    enqueue(&q, c);
    while (q.count != 0) {
        c = q.front->data;
        dequeue(&q);
        for (int i = 0; i < num_nodes; i++) {
            if (adjmtrx[c][i] == 1 && visited[i] == false) {
                ans = char(i + 65);
                answer += ans;
                answer += " ";
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int Graph::addDirectedEdge(string nodeA, string nodeB) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int nodea = nodeA.c_str()[0] - 65;
    int nodeb = nodeB.c_str()[0] - 65;
    adjmtrx[nodea][nodeb] = 1;
    if (nodes[nodea] == 0) {
        nodes[nodea] = 1;
        num_nodes++;
    }
    if (nodes[nodeb] == 0) {
        nodes[nodeb] = 1;
        num_nodes++;
    }
    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::addDirectedEdge(string nodeA, string nodeB, int weight) {
	/////////////////////////////////////////////////////////
	//////////  TODO: Implement From Here      //////////////
    int nodea = nodeA.c_str()[0] - 65;
    int nodeb = nodeB.c_str()[0] - 65;
    adjmtrx[nodea][nodeb] = weight;
    if (nodes[nodea] == 0) {
        nodes[nodea] = 1;
        num_nodes++;
    }
    if (nodes[nodeb] == 0) {
        nodes[nodeb] = 1;
        num_nodes++;
    }
    return 0;
	///////////      End of Implementation      /////////////
	///////////////////////////////////////////////////////
}


int Graph::addUndirectedEdge(string nodeA, string nodeB) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int nodea = nodeA.c_str()[0] - 65;
    int nodeb = nodeB.c_str()[0] - 65;
    adjmtrx[nodea][nodeb] = 1;
    adjmtrx[nodeb][nodea] = 1;
    if (nodes[nodea] == 0) {
        nodes[nodea] = 1;
        num_nodes++;
    }
    if (nodes[nodeb] == 0) {
        nodes[nodeb] = 1;
        num_nodes++;
    }
    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::addUndirectedEdge(string nodeA, string nodeB, int weight) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int nodea = nodeA.c_str()[0] - 65;
    int nodeb = nodeB.c_str()[0] - 65;
    adjmtrx[nodea][nodeb] = weight;
    adjmtrx[nodeb][nodea] = weight;
    if (nodes[nodea] == 0) {
        nodes[nodea] = 1;
        num_nodes++;
    }
    if (nodes[nodeb] == 0) {
        nodes[nodeb] = 1;
        num_nodes++;
    }
    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::countUndirectedCycle() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int count = 0;
    bool* visited = new bool[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = false;
    }
    
    //countcycle(count, visited, 0, 0);

    for (int i = 0; i < num_nodes; i++) {
        if (visited[i] == false) {
            countcycle(count, visited, i, i);
        }
        else continue;
    }
    delete[] visited;
    return count / 2;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

void Graph::countcycle(int& count, bool* visited, int c, int parent) {
    visited[c] = true;

    for (int i = 0; i < num_nodes; i++) {
        if (adjmtrx[c][i] == 1 && visited[i] == false) {
            countcycle(count, visited, i, c);
        }
        else if (adjmtrx[c][i] == 1 && i != parent && visited[i] == true) {

            count++;
            
            //cout << c << " " << i << endl;
        }
    }
}

string Graph::getTopologicalSort() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    string answer = "";
    int* indegree = new int[num_nodes];

    for (int i = 0; i < num_nodes; i++) {
        indegree[i] = 0;
        for (int j = 0; j < num_nodes; j++) {
            indegree[i] += adjmtrx[j][i];
        }
    }
    
    while (true) {
        int i;
        bool isfinish = true;

        for (i = 0; i < num_nodes; i++) {
            if (indegree[i] == 0) {
                break;
            }
            else if (indegree[i] > 0) {
                isfinish = false;
            }
        }
        if (i == num_nodes && isfinish == false) return "error";
        else if (i == num_nodes && isfinish == true) return answer;

        for (int j = 0; j < num_nodes; j++) {
            if (adjmtrx[i][j] == 1) {
                indegree[j]--;
            }
        }
        indegree[i] = -1;
        answer += char(i + 65);
        answer += " ";
    }

    delete[] indegree;
    return "error";
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::countDirectedCycle() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int count = 0;
    bool* visited = new bool[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = false;
    }
    
    //countcycle(count, visited, 0, 0);

    for (int i = 0; i < num_nodes; i++) {
        if (visited[i] == false) {
            countcycle(count, visited, i, i);
        }
        else continue;
    }
    delete[] visited;
    return count / 2;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

string Graph::getShortestPath(string source, string destination) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (i == j) continue;
            if (adjmtrx[i][j] == 0) {
                adjmtrx[i][j] = INF;
            }
        }
    }

    bool* visited = new bool[num_nodes];
    for (int i = 0; i < num_nodes; i++) visited[i] = false;

    int start = source.c_str()[0] - 65;
    int end = destination.c_str()[0] - 65;

    string* answers = new string[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        answers[i] = source + " ";
    }

    int* distance = new int[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        distance[i] = adjmtrx[start][i];
    }

    visited[start] = true;

    int minnode;

    for (int i = 0; i < num_nodes - 1; i++) {
        minnode = minweight(distance, visited);
        visited[minnode] = true;

        answers[minnode] += char(minnode + 65);
        answers[minnode] += " ";
        for (int j = 0; j < num_nodes; j++) {
            if (visited[j] == false && adjmtrx[minnode][j] != INF) {
                if (distance[minnode] + adjmtrx[minnode][j] < distance[j]) {
                    distance[j] = distance[minnode] + adjmtrx[minnode][j];
                    answers[j] = answers[minnode];
                }
            }
        }
    }
    delete[] visited;

    int dist = distance[end];
    delete[] distance;
    if (dist == INF) {
        return "error";
    }
    else {
        answers[end] += to_string(dist);
        string answ = answers[end];
        delete[] answers;
        return answ;
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int Graph::minweight(int* distance, bool* visited) {
    int min = INF;
    int minnode = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (distance[i] < min && visited[i] == false) {
            min = distance[i];
            minnode = i;
        }
    }
    return minnode;
}

string Graph::getAllShortestPaths() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////	
    string answer = "";

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (i == j) continue;
            if (adjmtrx[i][j] == 0) {
                adjmtrx[i][j] = INF;
            }
        }
    }

    //display();

    for (int k = 0; k < num_nodes; k++) {
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                if (safe_add(adjmtrx[i][k], adjmtrx[k][j]) < adjmtrx[i][j]) {
                    adjmtrx[i][j] = safe_add(adjmtrx[i][k], adjmtrx[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (adjmtrx[i][j] != INF) {
                answer += to_string(adjmtrx[i][j]);
            }
            else answer += "INF";
            answer += " ";
        }
        answer += "\n";
    }
    return answer;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int Graph::safe_add(int a, int b) {
    if (a > 0 && b > 0) {
        if (a + b < 0) {
            return INF;
        }
    }
    else if (a == INF || b == INF) {
        return INF;
    }
    else return a + b;
}

int Graph::primMST(ofstream &fout, string startNode) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    string answer = "";

    int start = startNode.c_str()[0] - 65;

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (i == j) continue;
            if (adjmtrx[i][j] == 0) {
                adjmtrx[i][j] = INF;
            }
        }
    }

    bool* visited = new bool[num_nodes];
    int* distance = new int[num_nodes];

    for (int i = 0; i < num_nodes; i++) {
        visited[i] = false;
        distance[i] = INF;
    }

    distance[start] = 0;
    
    int totaldist = 0;

    int* from = new int[num_nodes - 1];
    int* to = new int[num_nodes - 1];
    int* fromwho = new int[num_nodes];

    for (int i = 0; i < num_nodes - 1; i++) {
        from[i] = -1;
        to[i] = -1;
        fromwho[i] = -1;
    }

    //from[0] = start;


    int minnode = 0;

    //int forcorrecting = -1;
    for (int i = 0; i < num_nodes; i++) {

        minnode = minweight(distance, visited);
        visited[minnode] = true;
        if (i == 0) {
            from[i] = minnode;
        }
        else if (i != num_nodes - 1) {
            to[i - 1] = minnode;
            from[i - 1] = fromwho[minnode];
            from[i] = minnode;
        }
        else {
            to[i - 1] = minnode;
            from[i - 1] = fromwho[minnode];
        }
        //forcorrecting = minnode;
        for (int j = 0; j < num_nodes; j++) {
            if (adjmtrx[minnode][j] != INF) {
                if (adjmtrx[minnode][j] < distance[j] && visited[j] == false) {
                    distance[j] = adjmtrx[minnode][j];
                    fromwho[j] = minnode;
                }
            }

        }
     
    }

    for (int i = 0; i < num_nodes - 1; i++) {
        answer += char(from[i] + 65);
        answer += " ";
        answer += char(to[i] + 65);
        answer += " ";
        answer += to_string(adjmtrx[from[i]][to[i]]);
        answer += "\n";
    }

    for (int i = 0; i < num_nodes; i++) {
        totaldist += distance[i];
    }
    answer += to_string(totaldist);

    fout << answer << endl;
    delete[] visited;
    delete[] distance;
    delete[] from;
    delete[] to;
    delete[] fromwho;

    return 1;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int Graph::kruskalMST(ofstream &fout) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    string answer = "";

    int* parent = new int[num_nodes];
    int* numset = new int[num_nodes];
    edge* ans = new edge[num_nodes + 2];
    for (int i = 0; i < num_nodes; i++) {
        parent[i] = -1;
        numset[i] = 1;
    }
    for (int i = 0; i < num_nodes + 2; i++) {
        ans[i].from = 0;
        ans[i].to = 0;
        ans[i].weight = 0;
    }
    int idx = 0;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (adjmtrx[i][j] != 0) {
                ans[idx].weight = adjmtrx[i][j];
                adjmtrx[i][j] = 0;
                ans[idx].from = i;
                ans[idx].to = j;
                idx++;
            }
        }
    }

    sort(ans, ans + idx, edgecmp);

    int min;
    int cnt = 0;
    int i = 0;
    int a, b;
    int totaldist = 0;
    while (cnt < num_nodes - 1) {
        if (i < idx) {
            min = ans[i].weight;
            a = find_set(ans[i].from, parent);
            b = find_set(ans[i].to, parent);
            if (a != b) {
                cnt++;
                union_set(a, b, numset, parent);
                totaldist += min;
                answer += char(ans[i].from + 65);
                answer += " ";
                answer += char(ans[i].to + 65);
                answer += " ";
                answer += to_string(min);
                answer += "\n";
            }
            i++;
        }
    }

    answer += to_string(totaldist);
    fout << answer << endl;

    delete[] parent;
    delete[] numset;
    delete[] ans;
    return 1;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int Graph::find_set(int node, int* parent) {
    int par, i = -1, c = -1;
    for (i = node; (par = parent[i]) >= 0; i = par)
        ;
    c = i;
    for (i = node; (par = parent[i]) >= 0; i = par) {
        if (i < 0) break;
        parent[i] = c;
    }
    return c;
}

void Graph::union_set(int a, int b, int* numset, int* parent) {
    if (numset[a] < numset[b]) {
        parent[a] = b;
        numset[b] += numset[a];
    }
    else {
        parent[b] = a;
        numset[a] += numset[b];
    }
}