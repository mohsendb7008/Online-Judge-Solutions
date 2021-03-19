# Adding Words

memory = {}

while True:
    try:
        command = input().split()
        if command[0] == 'def':
            if command[1] in memory:
                del memory[memory[command[1]]]
                del memory[command[1]]
            memory[command[1]] = int(command[2])
            memory[int(command[2])] = command[1]
        elif command[0] == 'clear':
            memory.clear()
        elif command[0] == 'calc':
            if command[1] not in memory:
                print(' '.join(command[1:])+' unknown')
            else:
                value, unknown = memory[command[1]], False
                for i in range(2, len(command)-1, 2):
                    if command[i+1] not in memory:
                        unknown = True
                        break
                    if command[i] == '+':
                        value += memory[command[i+1]]
                    elif command[i] == '-':
                        value -= memory[command[i+1]]
                if unknown or (value not in memory):
                    print(' '.join(command[1:])+' unknown')
                else:
                    print(' '.join(command[1:])+f' {memory[value]}')
    except EOFError:
        break
