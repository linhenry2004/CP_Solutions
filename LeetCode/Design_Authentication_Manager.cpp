#include <bits/stdc++.h>
using namespace std;

class AuthenticationManager {
public:
    int timeout;
    unordered_map<string, int> tokenMap;
    set<pair<int, string>> timeMap;
    AuthenticationManager(int timeToLive) {
        timeout = timeToLive;
    }

    void cleanup (int currentTime) {
        while (!timeMap.empty() && (*timeMap.begin()).first <= currentTime) {
            tokenMap.erase((*timeMap.begin()).second);
            timeMap.erase(timeMap.begin());
        }
    }
    
    void generate(string tokenId, int currentTime) {
        timeMap.insert({currentTime + timeout, tokenId});
        tokenMap[tokenId] = currentTime + timeout;
    }
    
    void renew(string tokenId, int currentTime) {
        cleanup(currentTime);
        auto it = tokenMap.find(tokenId);
        if (it != tokenMap.end()) {
            timeMap.erase({it->second, tokenId});
            timeMap.insert({currentTime + timeout, tokenId});
            tokenMap[tokenId] = currentTime + timeout;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        cleanup(currentTime);
        return tokenMap.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */