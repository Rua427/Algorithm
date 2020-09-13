import sys

N = int(sys.stdin.readline())

l = []

for _ in range(N):
    l.append(int(sys.stdin.readline()))


def Swap(left, right):
    temp = left
    left = right
    right = temp

    return left, right
    

def Sorting(left, right):
    pivot = l[left]
    low = left
    high = right

    while(low < high):
        while(l[low] < pivot and low < right):
            low += 1
        while(l[high] > pivot and high > left):
            high -= 1
        if(low < high):
            l[low], l[high] = Swap(l[low], l[high])

    if(low > high):
        l[left], l[high] = Swap(l[left], l[high])
        return high
    


def QuickSort(left, right):
    if(left < right):
        pivot = Sorting(left, right)
        QuickSort(left, pivot-1)
        QuickSort(pivot+1, right)


QuickSort(0, len(l)-1)

for i in l:
    sys.stdout.write(str(i) + "\n")
