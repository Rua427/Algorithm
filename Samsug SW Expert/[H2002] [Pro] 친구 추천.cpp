#define MAX_RF      5
#define MAX_AF      10
#define MAX_USER    10001
#define MAX_FCNT    500001
 
struct USER {
    int userID;
    struct USER* prev;
};
 
USER* GetNewFriend(int id) {
    USER* newFriend = new USER;
    newFriend->userID = id;
    newFriend->prev = nullptr;
 
    return newFriend;
}
 
USER* userList[MAX_USER];
int userFriendCnt[MAX_USER];
 
int totalUserCnt = 0;
 
void init(int n) {
    totalUserCnt = n;
 
    for (int i = 0; i <= n; i++)
    {
        userList[i] = 0;
        userFriendCnt[i] = 0;
    }
}
 
void add(int id, int f, int ids[MAX_AF]) {
    userFriendCnt[id] += f;
 
    for (int i = 0; i < f; i++)
    {
        USER* nF = GetNewFriend(ids[i]);
        nF->prev = userList[id];
        userList[id] = nF;
 
        USER* pF = GetNewFriend(id);
        pF->prev = userList[ids[i]];
        userList[ids[i]] = pF;
 
        ++userFriendCnt[ids[i]];
    }
}
 
void Delete(int id1, int id2) {
    --userFriendCnt[id1];
    USER* d = userList[id1];
    for (USER *f = userList[id1]; f != 0; f = f->prev)
    {
        if (f->userID == id2) {
            if (d == f) {
                d = f->prev;
                userList[id1] = d;
            }
            else {
                d->prev = f->prev;
            }
            break;
        }
        d = f;
    }
}
 
void del(int id1, int id2) {
    Delete(id1, id2);
    Delete(id2, id1);
}
 
int recommend(int id, int list[MAX_RF]) {
    int count[MAX_USER] = { 0, };
 
    for (USER* f = userList[id]; f != 0; f = f->prev)
    {
        for (USER* nF = userList[f->userID]; nF != 0; nF = nF->prev) {
            ++count[nF->userID];
        }
    }
    for (USER* f = userList[id]; f != 0; f = f->prev) {
        count[f->userID] = 0;
    }
    count[id] = 0;
 
    int cnt = 0;
    for (cnt = 0; cnt < MAX_RF; cnt++)
    {
        int maxFriendCnt = 0;
        int maxFriendIdx = 0;
 
        for (int i = 1; i <= totalUserCnt; i++)
        {
            if (count[i] > maxFriendCnt) {
                maxFriendCnt = count[i];
                maxFriendIdx = i;
            }
        }
        if (maxFriendIdx == 0) {
            break;
        }
 
        list[cnt] = maxFriendIdx;
        count[maxFriendIdx] = 0;
    }
 
    return cnt;
}
