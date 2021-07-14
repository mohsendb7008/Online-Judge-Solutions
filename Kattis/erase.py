# Erase Securely

if __name__ == "__main__":
    ss = int(input()) % 2
    for a, b in zip(input(), input()):
        if (ss == 0 and a != b) or (ss == 1 and a == b):
            print("Deletion failed") 
            exit(0)
    print("Deletion succeeded")