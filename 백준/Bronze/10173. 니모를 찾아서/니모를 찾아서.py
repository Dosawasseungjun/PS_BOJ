while True : 
    S = input()
    if S == "EOI" : 
        break

    print("Found" if "nemo" in S.lower() else "Missing")