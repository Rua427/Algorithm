
/*
[문제 설명]

N대의 AI 로봇들과 트레이닝 센터가 있다.

각 로봇은 1번부터 N번까지 서로 다른 번호가 부여되어 있다. 이를 고유 번호라고 한다.

로봇에는 지능지수가 있다.

로봇이 센터에 있을 때 트레이닝이 되어 로봇의 지능지수는 1 시간마다 1씩 증가한다.

예로, 시각 10일 때 지능지수가 3이면 시각 15일 때 지능지수는 8이 된다.

로봇의 지능지수는 무한히 증가할 수 있다.

로봇은 작업에 투입될 수 있다.

작업에 로봇을 투입하는 방식에는 다음과 같이 2가지가 있다.


① 높은 지능 우선 방식 : 센터에 있는 로봇들 중 지능지수가 가장 높은 로봇부터 차례대로 투입한다. 만약, 지능지수가 같은 경우 고유 번호가 가장 작은 로봇을 투입한다.

② 낮은 지능 우선 방식 : 센터에 있는 로봇들 중 지능지수가 가장 낮은 로봇부터 차례대로 투입한다. 만약, 지능지수가 같은 경우 고유 번호가 가장 작은 로봇을 투입한다.


만약, 센터에 로봇 1, 2, 3, 4, 5가 있고 로봇의 지능지수가 각각 10, 9, 10, 15, 7이라고 생각하자.

높은 지능 우선 방식으로 2대의 로봇을 작업에 투입하고자 한다면 로봇 4, 1이 투입된다.

낮은 지능 우선 방식으로 3대의 로봇을 작업에 투입하고자 한다면 로봇 5, 2, 1이 투입된다.

작업 중인 로봇은 지능지수가 올라가거나 내려가지 않는다. 또한, 로봇이 센터로 복귀할 때까지 새로운 작업에 투입되지 않는다.

로봇이 작업에서 복귀할 때 센터로 바로 복귀하고 트레이닝을 시작한다.

작업 중인 로봇은 고장 날 수 있다.

만약, 로봇이 고장 나면 로봇은 센터로 바로 복귀하고 수리가 완료될 때까지 해당 로봇은 작업에 투입되지 않는다.

수리가 완료된 순간 로봇의 지능지수는 0이 된다. 그때부터 로봇은 트레이닝을 시작하고 작업에 투입될 수 있는 상태가 된다.

수리가 완료된 로봇은 이전 투입되었던 작업으로 다시 투입되는 것이 아니다.

이와 같이 AI 로봇을 관리하는 프로그램을 작성하라.



아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 Java에 대해서는 제공되는 Solution.java와 UserSolution.java를 참고하라.

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.


                                    
 
void init(int N)

테스트 케이스에대한 초기화하는 함수. 각 테스트 케이스의 처음에 1회호출된다.

N은 로봇의 개수이다. 각 로봇은 1부터 N까지서로 다른 고유 번호가 부여되어 있다.

현재 시각은 0이다.

초기에 모든 로봇은센터에 있고 지능지수는 0이다. 고장 난 로봇은 없다.

Parameters

   N : 로봇의대수 (10 ≤ N ≤ 50,000)
 

int callJob(int cTime, int wID, int mNum, intmOpt)

현재 시각이 cTime이다. ID가 wID인 작업에 mNum대의 로봇을 투입한다.

해당 작업에 투입된 로봇들의 고유 번호를 모두 합한 값을 반환한다.

mOpt =0인 경우, 높은 지능 우선 방식으로 로봇을 투입한다.

mOpt =1인 경우, 낮은 지능 우선 방식으로 로봇을 투입한다.

각 투입 방식의 자세한 설명은 본문 내용을 참조하라.

고장 나거나 작업 중인 로봇은 해당 작업에 투입되지 않는다.

작업에 투입 가능한 로봇의 수보다 더 많이 투입을 요청하는 경우는 발생하지 않음을 보장한다. 

각테스트 케이스에서 wID는 해당 함수가 처음 호출할 때 1이고호출될 때마다 1씩 증가한다.

Parameters

   cTime: 현재 시각 (1 ≤ cTime ≤ 1,000,000,000)

   wID: 작업 ID (1 ≤ wID ≤ 50,000)

   mNum : 작업에 투입할 로봇의 대수 (1 ≤ mNum ≤ N)

   mOpt : 로봇을 투입하는 방식 (mOpt= 0 or 1)

 

Returns

   투입된 로봇들의 고유 번호 총합
 

void returnJob(int cTime, int wID)
 

현재 시각이 cTime이다. ID가 wID인 작업에 투입된 로봇들이 센터로 복귀하고 트레이닝을바로 시작한다.

 

callJob 함수로 호출된 적이 있는 wID 값만 입력으로 들어오는 것을 보장한다.

같은 wID 값으로 두 번 이상 들어오는 경우도 없다.

 

투입된 로봇들이 모두 고장 나 복귀하는 로봇이 없는 경우도 있다.

 

Parameters

   cTime: 현재 시각 (1 ≤ cTime ≤ 1,000,000,000)

   wID : 작업 ID (1 ≤ wID ≤ 50,000)
 

void broken(int cTime, int rID)
 

현재 시각이 cTime이다. 작업중이고 고유 번호가 rID인 로봇이 고장 난다.

 

해당 로봇은 즉시 센터로 복귀한다. 해당 로봇은 수리가 되기 전까지 작업에투입할 수 없다.

 

해당 로봇이 이미 고장 난 로봇이거나 센터에서 트레이닝 중인 경우 이 함수가 호출되면 무시된다.

 

Parameters

   cTime: 현재 시각 (1 ≤ cTime ≤ 1,000,000,000)

   rID: 로봇번호 (1 ≤ rID ≤ N)
 

void repair(int cTime, int rID)
 

현재 시각이 cTime이다. 번호가 rID인 로봇의 수리가 완료된다.

 

해당 로봇은 다시 작업에 투입될 수 있다.

 

수리가 완료된 로봇은 지능지수가 0이 되고 트레이닝을 시작한다.

 

해당 로봇이 고장 난 로봇이 아닌 경우 이 함수가 호출되면 무시된다.

 

Parameters

   cTime: 현재 시각 (1 ≤ cTime ≤ 1,000,000,000)

   rID : 로봇 번호 (1 ≤ rID ≤ N)
 

int check(int cTime, int rID)
 

현재 시각이 cTime이다. 고유 번호가 rID인 로봇의 상태를 확인한다.

 

로봇의 상태에 따라 다음 중 한가지 값을 반환한다.

  1) 만약 로봇이 고장 난 상태이면 0을 반환한다.

  2) 만약 로봇이 작업에 투입되어 있으면, (투입된 작업의 ID) * (-1)을 반환한다.

  3) 그 외의 경우는 로봇의 지능지수를 반환한다.

 

Parameters

   cTime: 현재 시각 (1 ≤ cTime ≤ 1,000,000,000)

   rID : 로봇의 고유 번호 (1 ≤ rID ≤ N)

 

Returns

   로봇의상태를 나타내는 값
 
[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 한 번 호출된다.

2. 로봇의 총 대수 N은 10 이상 50,000 이하의 정수이다.

3. 시각 cTime은 1 이상 1,000,000,000 이하의 정수이다.

4. 각 테스트 케이스에서 init()을 제외한 함수가 호출될 때마다 cTime은 증가하는 값으로 주어진다.

5. 각 테스트 케이스에서 callJob() 함수를 통해 투입되는 로봇 대수의 총합은 200,000 이하이다.

6. 각 테스트 케이스에서 init() 을 제외한 함수의 호출 횟수의 총합은 50,000 이하이다.

 


[입출력]



입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

Sample input 에 대한 정답 출력 결과는 아래와 같은 형태로 보여진다.


   
 
#1 100

#2 100

#3 100

…
 
 */











#include <list>
#include <set>
#include <map>
using namespace std;
 
int time = 0;
enum class STATUS {
    WORKING = 0,
    TRAINNING,
    REPAIRING,
};
 
 
class Robot {
public:
    int rID;
    int rIQ;
    int wID;
    int wS;   // 작업 시작 시간
    int wT;   //작업 시간
    int rT; // 수리 시간
    STATUS status;
 
    Robot() {
        rID = 0;
        rIQ = 0;
        wID = 0;
        wS = 0;
        wT = 0;
        rT = 0;
 
        status = STATUS::TRAINNING;
    }
    Robot(int _id) {
        rID = _id;
        rIQ = 0;
        wID = 0;
        wS = 0;
        wT = 0;
        rT = 0;
         
        status = STATUS::TRAINNING;
    }
 
    void Update() {
        rIQ = time - wT - rT;
    }
 
    void init(int t) {
        wS = 0;
        wT = 0;
        rT = t;
        rIQ = 0;
    }
 
    int CalcIQ() {
        return time - wT - rT;
    }
 
    int ReturnIQ () {
        if (status == STATUS::REPAIRING)
            return 0;
        if (status == STATUS::WORKING)
            return wID * -1;
        else
            return CalcIQ();
    }
};
 
int opt = 0;
// 0 내림차순 1 오름차순
struct Order {
 
    bool operator() (const Robot* left, const Robot* right) const {
        // 같을시 ID로 정렬
        if ((time - left->rT - left->wT) == (time - right->rT - right->wT)) {
            return left->rID < right->rID;
        }
        // 지능순 정렬
        else {
            return opt ? (time - left->rT - left->wT) < (time - right->rT - right->wT) :
                (time - left->rT - left->wT) > (time - right->rT - right->wT);
        }
    }
};
 
Robot* robot;
set<Robot*, Order> center[2];
map<int, set<Robot*>> work;
int robotNumber = 0;
 
void init(int N)
{
    robotNumber = N;
    robot = new Robot[50010]();
 
    center[0].clear();
    center[1].clear();
    work.clear();
         
    int cnt = 1;
    for (int i = 0; i < N; i++) {
        robot[i].rID = i + 1;
        opt = 0;
        center[opt].insert(&robot[i]);
        opt = 1;
        center[opt].insert(&robot[i]);
    }
     
}
 
int callJob(int cTime, int wID, int mNum, int mOpt)
{
    int cnt = 0;
    opt = mOpt;
    auto iter = center[opt].begin();
    int sum = 0;
 
    for (; iter != center[opt].end(); iter++) {
        if (cnt >= mNum)
            break;
 
        if ((*iter)->status == STATUS::TRAINNING ? 1 : 0) {
            (*iter)->status = STATUS::WORKING;
            (*iter)->wID = wID;
            (*iter)->wS = cTime;
            work[wID].insert(*iter);
 
            cnt++;
            sum += (*iter)->rID;
        }
    }
 
    // delete
    auto it = work[wID].begin();
     
    for (; it != work[wID].end(); it++) {
        opt = 0;
        center[opt].erase(*it);
        opt = 1;
        center[opt].erase(*it);
    }
 
 
    time = cTime;
 
    return sum;
}
 
void returnJob(int cTime, int wID)
{
    auto iter = work[wID].begin();
    time = cTime;
 
    //for (auto it = center[0].begin(); it != center[0].end(); it++) {
    //  (*it)->Update();
    //}
    //for (auto it = center[1].begin(); it != center[1].end(); it++) {
    //  (*it)->Update();
    //}
 
 
    for (; iter != work[wID].end(); iter++) {
        (*iter)->wID = 0;
        (*iter)->wT += cTime - (*iter)->wS;
        //(*iter)->Update();
        (*iter)->status = STATUS::TRAINNING;
 
        opt = 0;
        center[opt].insert(*iter);
        opt = 1;
        center[opt].insert(*iter);
    }
 
    work[wID].clear();
}
 
void broken(int cTime, int rID)
{
    time = cTime;
    if (robot[rID - 1].status == STATUS::WORKING) {
        auto iter = work[robot[rID - 1].wID].begin();
        for (; iter != work[robot[rID - 1].wID].end(); iter++) {
            if (*iter == &robot[rID - 1]) {
                work[robot[rID - 1].wID].erase(&robot[rID - 1]);
 
                robot[rID - 1].wID = 0;
                robot[rID - 1].status = STATUS::REPAIRING;
 
                return;
            }
        }
    }
}
 
void repair(int cTime, int rID)
{
    time = cTime;
    if (robot[rID - 1].status != STATUS::REPAIRING) {
        return;
    }
    //for (auto it = center[0].begin(); it != center[0].end(); it++) {
    //  (*it)->Update();
    //}
    //for (auto it = center[1].begin(); it != center[1].end(); it++) {
    //  (*it)->Update();
    //}
 
 
    robot[rID - 1].status = STATUS::TRAINNING;
    robot[rID - 1].init(cTime);
 
    opt = 0;
    center[opt].insert(&robot[rID - 1]);
    opt = 1;
    center[opt].insert(&robot[rID - 1]);
}
 
int check(int cTime, int rID)
{
    time = cTime;
    int res = robot[rID - 1].ReturnIQ();
    return res;
}
