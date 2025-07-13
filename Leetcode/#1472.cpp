class Node{
public:
    Node* prev;
    string data;
    Node* after;

    Node(string _data) {
        data = _data;
        prev = nullptr;
        after = nullptr;
    }    
};
class BrowserHistory {
public:
    Node* currentPage = new Node("");
    
    BrowserHistory(string homepage) {
        currentPage->data = homepage;
    }
    
    void visit(string url) {
        Node* newPage = new Node(url);
        currentPage->after = newPage;
        newPage->prev = currentPage;
        currentPage = newPage;
    }
    
    string back(int steps) {
        while(steps) {
            if(currentPage->prev)
                currentPage = currentPage->prev;
            else break;
            steps--;
        }
        return currentPage->data;
    }
    
    string forward(int steps) {
        while(steps) {
            if(currentPage->after)
                currentPage = currentPage->after;
            else break;
            steps--;
        }
        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */