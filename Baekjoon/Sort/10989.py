import sys

N = int(sys.stdin.readline())

numbers = []
count = [0] * 10001

for _ in range(N):
    num = int(sys.stdin.readline())

    if(count[num] == 0):
        numbers.append(num)
    count[num] += 1
    

def Swap(left, right):
    temp = left
    left = right
    right = temp

    return left, right

def Sorting(start, end):
    pivot = numbers[(start + end) // 2]
    left = start
    right = end

    while(left < right):
        while(numbers[left] < pivot and left < right):
            left += 1
        while(numbers[right] > pivot):
            right -= 1

        if(left < right):
            numbers[left], numbers[right] = Swap(numbers[left], numbers[right])
        
    return right

def QuickSort(start, end):

    if(start >= end):
        return
    
    pivot = Sorting(start,end)
    QuickSort(start, pivot-1)
    QuickSort(pivot+1, end)


QuickSort(0, len(numbers)-1)

for n in numbers:
    for _ in range(count[n]):
        sys.stdout.write(str(n)+"\n")
