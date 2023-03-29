class BinaryHeap:
    massive = []
    length = 0

    def __init__(self):
        massive = []
        length = 0

    def swap(self, index_1, index_2):
        temp = self.massive[index_1]
        self.massive[index_1] = self.massive[index_2]
        self.massive[index_2] = temp

    def sift_up(self, index):
        while index != 0:
            if self.massive[index] > self.massive[(index + 1) // 2 - 1]:
                self.swap(index, (index + 1) // 2 - 1)
                index = (index + 1) // 2 - 1
            else:
                return

    def sift_down(self, index):
        length = self.length
        while (index + 1) * 2 <= length:
            value = self.massive[index]
            value_1 = self.massive[(index + 1) * 2 - 1]
            if (index + 1) * 2 + 1 <= length:
                value_2 = self.massive[(index + 1) * 2]
                if (value < value_1) or (value < value_2):
                    if value_1 > value_2:
                        self.swap(index, (index + 1) * 2 - 1)
                        index = (index + 1) * 2 - 1
                    else:
                        self.swap(index, (index + 1) * 2)
                        index = (index + 1) * 2
                else:
                    return
            else:
                if value < value_1:
                    self.swap(index, (index + 1) * 2 - 1)
                    index = (index + 1) * 2 - 1
                else:
                    return

    def insert(self, value):
        self.massive.append(value)
        self.length += 1
        if self.length == 1:
            return
        if value > self.massive[(self.length + 1) // 2 - 1]:
            self.sift_up(self.length - 1)

    def extract_max(self):
        assert(self.length > 0)
        answer = self.massive[0]
        if self.length > 1:
            self.massive[0] = self.massive.pop(self.length - 1)
        else:
            self.massive = []
        self.length -= 1
        self.sift_down(0)
        return answer

    def __str__(self):
        return str(self.massive)


heap_1 = BinaryHeap()
n = int(input())
for i in range(n):
    line = input().split()
    if line[0] == "ExtractMax":
        print(heap_1.extract_max())
    elif line[0] == "Insert":
        heap_1.insert(int(line[1]))
    else:
        exit('wrong input')
