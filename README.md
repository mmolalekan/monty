Project title: 
    0x19. C - Stacks, Queues - LIFO, FIFO
Team members:
    Emmanuel Ifeanyichukwu @Mire-web
    Abdulmuhaymin Olalekan @mmolalekan
Task 0: push, pall
Implement the push and pall opcodes.

The push opcode

    The opcode push pushes an element to the stack.

    Usage: push <int>
    where <int> is an integer
    if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
    where is the line number in the file
    You won’t have to deal with overflows. Use the atoi function
    The pall opcode

    The opcode pall prints all the values on the stack, starting from the top of the stack.

    Usage pall
    Format: see example
    If the stack is empty, don’t print anything

Task 1: pint
    Implement the pint opcode.

    The pint opcode

    The opcode pint prints the value at the top of the stack, followed by a new line.

    Usage: pint
    If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

Task 2: pop
    
    Implement the pop opcode.

    The pop opcode

    The opcode pop removes the top element of the stack.

    Usage: pop
    If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE
    
Task 3: Swap
    Implement the swap opcode.

    The swap opcode

    The opcode swap swaps the top two elements of the stack.

    Usage: swap
    If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
    
Task 4: add
    
    Implement the add opcode.

    The add opcode

    The opcode add adds the top two elements of the stack.

    Usage: add
    If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
    The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    The top element of the stack contains the result
    The stack is one element shorter

Task 5: nop
    
    Implement the nop opcode.

    The nop opcode

    The opcode nop doesn’t do anything.

    Usage: nop
    
Task 6: sub
    
     Implement the sub opcode.

    The sub opcode

    The opcode sub subtracts the top element of the stack from the second top element of the stack.

    Usage: sub
    If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
    The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    The top element of the stack contains the result
    The stack is one element shorter
    
Task 7: div
    
    Implement the div opcode.

    The div opcode

    The opcode div divides the second top element of the stack by the top element of the stack.

    Usage: div
    If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
    The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    The top element of the stack contains the result
    The stack is one element shorter
    If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE
    
Task 8: mul
    
    Implement the mul opcode.

    The mul opcode

    The opcode mul multiplies the second top element of the stack with the top element of the stack.

    Usage: mul
    If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
    The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    The top element of the stack contains the result
    The stack is one element shorter
    
Task 9: mod

    Implement the mod opcode.

    The mod opcode

    The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.

    Usage: mod
    If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
    The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    The top element of the stack contains the result
    The stack is one element shorter
    If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE
    
Task 10: comments
Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).
