import sys

#heapsize
N = int(sys.stdin.readline())

#queue
queue = []
for _ in range(N):
    queue.append(int(sys.stdin.readline()))

def heapify(unsorted, index, heap_size):
    _max = index

    left_index = 2 * index + 1
    right_index = 2 * index + 2

    if(left_index < heap_size and unsorted[_max] < unsorted[left_index]):
        _max = left_index
    if(right_index < heap_size and unsorted[_max] < unsorted[right_index]):
        _max = right_index
    
    if(_max != index):
        unsorted[_max], unsorted[index] = unsorted[index], unsorted[_max]

        heapify(unsorted, _max, heap_size)


def heapsort(unsorted):
    for i in range(N // 2 - 1, -1, -1):
        heapify(unsorted, i, N)
    for i in range(N - 1, 0, -1):
        unsorted[0], unsorted[i] = unsorted[i], unsorted[0]
        heapify(unsorted, 0, i)
    
    return unsorted

queue = heapsort(queue)
for i in queue:
    sys.stdout.write(str(i) + "\n")
