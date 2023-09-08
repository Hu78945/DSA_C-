# Recursion

A recursive function is a function that calls itself, creating a sequence of nested function calls. For example:

```c
int fun(){
    if (<base_condition>){
        func()
    }else{
        return 0;
    }
}
```

There must be a base condition that terminates the function, or else it will run infinitely.

## Phases of Recursive Function

There are two phases of recursive functions:

1. **Ascending Calling**:
   - In this phase, the function calls itself at the beginning.
   - Example:
     ```c
     void func(int n){
         if (n > 0){
             // 1. Calling
             // 2. func(n-1)*2
             // 3. Returning
         }
     }
     ```

2. **Descending Calling**:
   - In this phase, the function calls itself at the end.
   - The main difference between loops and recursive functions is that recursive functions have both ascending and descending phases.

## How Recursion Uses Stack

When a recursive function is called, it creates a stack frame or activation record for each call until the exit condition is met. It then starts popping out of the stack using the Last In First Out (LIFO) strategy, depending on the number of calls made, until it finally returns to the main function. For n calls, there will be n+1 calls, with the last one being where the exit condition is met. The time complexity of recursive functions is O(n), and they are memory-consuming functions.

## Time Complexity Of Recursive Function

The time complexity of a recursive function can be determined using a technique called recurrence relation.

## Types Of Recursion

There are several types of recursion:

- **Tail Recursion**:
  - If the function calls itself and it's the last statement in the function, it is tail recursion.
  - Example:
    ```c
    void fun(int x){
        if (x > 0){
            printf("%d ", x);
            fun(x - 1);
        }
    }
    ```
  - In tail recursion, no operations are performed at the return time.

- **Head Recursion**:
  - If the first statement inside a function is a function calling itself, it is head recursion.
  - Example:
    ```c
    void fun2(int x){
        if (x > 0){
            fun(x - 1);
            printf("%d ", x);
        }
    }
    ```

- **Tree Recursion**:
  - If a recursive function calls itself more than once, it is tree recursion.
  - Example:
    ```c
    void fun(int x){
        if (x > 0){
            // ...
            fun(x - 1);
            // ...
            fun(x - 1);
            // ...
        }
    }
    ```

- **Indirect Recursion**:
  - In indirect recursion, one function calls another function which, in turn, calls the first function in a circular manner.
  - Example:
    ```c
    void A(int n){
        if (<condition>){
            // ...
            B(n - 1);
        }
    }
    
    void B(int n){
        if (<condition>){
            // ...
            A(n - 3);
        }
    }
    ```

- **Nested Recursion**:
  - In nested recursion, parameters are passed as a recursive call.
  - Example:
    ```c
    void fun(int n){
        if (<condition>){
            // ...
            fun(fun(n - 1));
        }
    }
    ```
