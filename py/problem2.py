def shiftStacktoStack(src_stack: list, dst_stack: list):
    if len(src_stack) > 0:
        while len(src_stack) > 0:
            dst_stack.append(src_stack.pop(-1))        

class QueueWithTwoStacks(object):
    def __init__(self) -> None:
        self._stackNewestOnTop = []
        self._stackOldestOnTop = []

    def enqueue(self, val):
        self._stackNewestOnTop.append(val)
     
    def peak(self):
        if len(self._stackOldestOnTop) < 1:
            if len(self._stackNewestOnTop) > 0:
                shiftStacktoStack(self._stackNewestOnTop, self._stackOldestOnTop)
            else:  
                return 0
        return self._stackOldestOnTop[-1]

    def dequeue(self):
        if len(self._stackOldestOnTop) < 1:
            if len(self._stackNewestOnTop) > 0:
                shiftStacktoStack(self._stackNewestOnTop, self._stackOldestOnTop)
            else:  
                return 0
        return self._stackOldestOnTop.pop(-1)

def testQueueWithTwoStacks():
    testQueueWithTwoStacksobj = QueueWithTwoStacks()
    testArr = (1,2,3,4,5,6,7,8,9,10)
    index = 0
    print("  Test 1")
    for index in range(10):
        testQueueWithTwoStacksobj.enqueue(testArr[index])


    for index in range(10):
        print("Peak: ", testQueueWithTwoStacksobj.peak())
        print("Pop: ", testQueueWithTwoStacksobj.dequeue())

    print("-------------")
    print("  Test 2")
    for index in range(5):
        testQueueWithTwoStacksobj.enqueue(testArr[index])


    for index in range(2):
        print("Peak: ", testQueueWithTwoStacksobj.peak())
        print("Pop: ", testQueueWithTwoStacksobj.dequeue())


    for index in range(5, 10):
        testQueueWithTwoStacksobj.enqueue(testArr[index])


    for index in range(10):
        print("Peak: ", testQueueWithTwoStacksobj.peak())
        print("Pop: ", testQueueWithTwoStacksobj.dequeue())

