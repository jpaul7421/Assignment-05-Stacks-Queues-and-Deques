# Assignment 05: Stacks, Queues, and Deques

## Approach

This assignment implements six data structures from scratch: an array-based stack, linked-list stack, array-based queue, linked-list queue, array-based deque, and doubly linked-list deque. The implementation does not use `<stack>`, `<queue>`, `<deque>`, or another container that directly implements a required ADT.

The array-based structures use fixed-capacity raw arrays. The array queue and deque use circular indexing so elements do not need to be shifted after each removal. If an array is full, an insertion is rejected. The linked queue stores front and back pointers. The linked deque uses previous and next pointers so both ends can be accessed directly.

The complete implementation is in [`assignment05.cpp`](assignment05.cpp).

## Time and Space Complexity

Let `n` be the number of stored elements.

| Operation or storage | Complexity | Explanation |
|---|---:|---|
| `push`, `pop`, and `peek` | O(1) | The stack accesses its top directly. |
| `enqueue`, `dequeue`, and `front` | O(1) | The queue accesses its front and back directly. |
| Deque insertion, removal, `front`, and `back` | O(1) | Both ends are accessed directly. |
| Array insertion when full | O(1) | The operation is rejected without shifting or resizing. |
| Fixed-capacity array space | O(1) | Each array has a constant capacity of 8. |
| Linked-list space | O(n) | One node is allocated for each stored element. |

No operation in this design becomes O(n). The fixed-capacity arrays avoid resizing, while the linked structures maintain direct pointers to the necessary ends.

## Representative Test Cases

The test cases below are run by the included test driver. Each structure is tested for insertion, removal, and empty handling.

| Test | Operations | Expected result |
|---|---|---|
| Empty handling | Create each structure and call its removal operation while empty | Empty removal is handled with `underflow_error`. |
| Array stack | Push 10, 20, 30, 40, 50; peek; pop; push 60; drain | `peek` is 50; removals are 50, 60, 40, 30, 20, 10; structure is empty. |
| Linked stack | Push 1, 11, 21, 31, 41; peek; pop; push 51; drain | `peek` is 41; removals are 41, 51, 31, 21, 11, 1; structure is empty. |
| Array queue | Enqueue 10, 20, 30, 40, 50; dequeue twice; enqueue 60 and 70; drain | `front` is 10; FIFO removals are 10, 20, 30, 40, 50, 60, 70; structure is empty. |
| Linked queue | Enqueue 1, 11, 21, 31, 41; dequeue twice; enqueue 51 and 61; drain | `front` is 1; FIFO removals are 1, 11, 21, 31, 41, 51, 61; structure is empty. |
| Array deque | Push at both ends; pop from both ends; drain | Front and back values remain correct; both-end removals succeed; structure is empty. |
| Linked deque | Push at both ends; pop from both ends; drain | Front and back values remain correct; both-end removals succeed; structure is empty. |
| Circular indexing | Remove from the front of an array queue/deque, then add values at the back or front | Values remain in the correct logical order without shifting elements. |

## Test Results

The stack tests confirm LIFO order, the queue tests confirm FIFO order, and the deque tests confirm insertion and removal from both ends. The array-based queue and deque also test circular indexing while maintaining the correct logical order. All tests produced the expected results, and each structure ended empty after its removal sequence.
