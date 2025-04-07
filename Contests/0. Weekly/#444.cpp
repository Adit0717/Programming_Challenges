/*
Q1. Minimum pair removal to make the array sorted
Given an array nums, you can perform the following operation any number of times:
Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.
An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

Example 1:
Input: nums = [5,2,3,1]
Output: 2
Explanation:
The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.

Example 2:
Input: nums = [1,2,2]
Output: 0
Explanation:
The array nums is already sorted.
*/

class Solution {
public:
    bool isAscending(vector<int> &nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while(!isAscending(nums)) {
            int sum = INT_MAX, index = -1;
            for(int i = 0; i < nums.size() - 1; i++) {
                if(sum > nums[i] + nums[i + 1]) {
                    sum = nums[i] + nums[i + 1];
                    index = i;
                }                    
            }
            nums.erase(nums.begin() + index + 1);
            nums[index] = sum;
            count++;            
        }
        return count;
    }
};

/*
Q2. Implement Router
Design a data structure that can efficiently manage data packets in a network router. Each data packet consists of the following attributes:
source: A unique identifier for the machine that generated the packet.
destination: A unique identifier for the target machine.
timestamp: The time at which the packet arrived at the router.
Implement the Router class:

Router(int memoryLimit): Initializes the Router object with a fixed memory limit.

memoryLimit is the maximum number of packets the router can store at any given time.
If adding a new packet would exceed this limit, the oldest packet must be removed to free up space.
bool addPacket(int source, int destination, int timestamp): Adds a packet with the given attributes to the router.

A packet is considered a duplicate if another packet with the same source, destination, and timestamp already exists in the router.
Return true if the packet is successfully added (i.e., it is not a duplicate); otherwise return false.
int[] forwardPacket(): Forwards the next packet in FIFO (First In First Out) order.

Remove the packet from storage.
Return the packet as an array [source, destination, timestamp].
If there are no packets to forward, return an empty array.
int getCount(int destination, int startTime, int endTime):

Returns the number of packets currently stored in the router (i.e., not yet forwarded) that have the specified destination and have timestamps in the inclusive range [startTime, endTime].
Note that queries for addPacket will be made in increasing order of timestamp.

Example 1:

Input:
["Router", "addPacket", "addPacket", "addPacket", "addPacket", "addPacket", "forwardPacket", "addPacket", "getCount"]
[[3], [1, 4, 90], [2, 5, 90], [1, 4, 90], [3, 5, 95], [4, 5, 105], [], [5, 2, 110], [5, 100, 110]]

Output:
[null, true, true, false, true, true, [2, 5, 90], true, 1]

Explanation

Router router = new Router(3); // Initialize Router with memoryLimit of 3.
router.addPacket(1, 4, 90); // Packet is added. Return True.
router.addPacket(2, 5, 90); // Packet is added. Return True.
router.addPacket(1, 4, 90); // This is a duplicate packet. Return False.
router.addPacket(3, 5, 95); // Packet is added. Return True
router.addPacket(4, 5, 105); // Packet is added, [1, 4, 90] is removed as number of packets exceeds memoryLimit. Return True.
router.forwardPacket(); // Return [2, 5, 90] and remove it from router.
router.addPacket(5, 2, 110); // Packet is added. Return True.
router.getCount(5, 100, 110); // The only packet with destination 5 and timestamp in the inclusive range [100, 110] is [4, 5, 105]. Return 1.©leetcode
*/
class Router {
private:
    int memoryLimit;

    struct Packet {
        int source;
        int destination;
        int timestamp;

        Packet(int s, int d, int t) : source(s), destination(d), timestamp(t) {}
    };

    deque<Packet> queue;
    unordered_set<string> packetSet;
    unordered_map<int, multiset<int>> destTimeMap;

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (packetSet.count(key)) return false;

        if ((int)queue.size() == memoryLimit) {
            Packet old = queue.front();
            queue.pop_front();
            string oldKey = makeKey(old.source, old.destination, old.timestamp);
            packetSet.erase(oldKey);

            auto& times = destTimeMap[old.destination];
            times.erase(times.find(old.timestamp));
            if (times.empty()) destTimeMap.erase(old.destination);
        }

        queue.emplace_back(source, destination, timestamp);
        packetSet.insert(key);
        destTimeMap[destination].insert(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (queue.empty()) return {};

        Packet pkt = queue.front();
        queue.pop_front();

        string key = makeKey(pkt.source, pkt.destination, pkt.timestamp);
        packetSet.erase(key);

        auto& times = destTimeMap[pkt.destination];
        times.erase(times.find(pkt.timestamp));
        if (times.empty()) destTimeMap.erase(pkt.destination);

        return {pkt.source, pkt.destination, pkt.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destTimeMap.count(destination)) return 0;

        auto& times = destTimeMap[destination];
        auto it1 = times.lower_bound(startTime);
        auto it2 = times.upper_bound(endTime);
        return distance(it1, it2);
    }
};

//Q4. Minimum pair removal to make the array sorted
/* Same as question 1 but with extra input constraints
1 <= nums.length <= 105
-10^9 <= nums[i] <= 10^9 
*/