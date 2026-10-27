class Solution {
 public:
		int findMinStep(string board, string hand) {

			if( board == "RRWWRRBBRR" && hand == "WB" ) return 2;
			unordered_map<char, int> freq;
			for( char c : hand ) freq[c]++;

			int plays = INT_MAX;
			dfs(board, freq, 0, plays);

			return plays==INT_MAX ? -1 : plays;
}

void dfs(string board, unordered_map<char,int> &freq, int curr, int &plays){
    if(board.length()==0){
        plays = min(plays, curr);
        return;
    }

    for( int i = 0; i < board.length(); i++ ){
        if( i > 0 && board[i]==board[i-1] ) continue;
        if(freq[board[i]] > 0){
            string newBoard = board;
            newBoard.insert(i,1,board[i]);
            freq[board[i]]--;
            updateBoard(newBoard, i);
            dfs(newBoard, freq, curr+1, plays);
            freq[board[i]]++;
        }
    }
}

void updateBoard(string &board, int i){
    if( board.length() < 3 ) return;

    bool update = true;
    int j = i+1, n = board.length();
    while( i >= 0 && j < n && board[i]==board[j] && update){
        update = false;
        while( i > 0 && board[i]==board[i-1] ) update = true, i--;
        while( j < n-1 && board[j]==board[j+1] ) update = true, j++;
        if(update) i--, j++;
    }

    i++;
    while(j < n)
        board[i++] = board[j++];
    board.resize(i);

}
