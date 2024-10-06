import random
import time
import os

def roll_dice():
    result = random.randint(1, 6)
    print(f"Dice roll: {result}")
    return result

def main():
    lost_total_att = 0
    lost_total_def = 0

    troup_att = int(input("Troup attack amount: "))

    while True:
        dice = [0] * 3

        max_att1 = max_att2 = max_def1 = max_def2 = 0

        print(f"Troups attacking: {troup_att}")
        troup_def = int(input("Troup defense amount: "))

        print(f"Troups defending: {troup_def}")

        troup_att_old = troup_att
        troup_def_old = troup_def

        random.seed(time.time())

        while troup_att >= 3 and troup_def >= 1:
            dice = [roll_dice() for _ in range(3)]
            dice.sort()

            max_att1, max_att2 = dice[2], dice[1]

            if troup_def >= 2 and max_att2 <= 3:
                dice[1], dice[2] = roll_dice(), roll_dice()
                dice.sort()

                max_def1, max_def2 = dice[2], dice[1]

                if max_def1 >= max_att1:
                    troup_att -= 1
                    print(f"Defense wins: {max_def1} vs attack: {max_att1}")
                else:
                    troup_def -= 1
                    print(f"Attack wins: {max_att1} vs defense: {max_def1}")

                if max_def2 >= max_att2:
                    troup_att -= 1
                    print(f"Defense wins 2nd dice: {max_def2} vs attack: {max_att2}")
                else:
                    troup_def -= 1
                    print(f"Attack wins 2nd dice: {max_att2} vs defense: {max_def2}")
            else:
                max_def1 = roll_dice()
                if max_def1 >= max_att1:
                    troup_att -= 1
                    print(f"Defense wins 1 dice: {max_def1} vs attack: {max_att1}")
                else:
                    troup_def -= 1
                    print(f"Attack wins 1 dice: {max_att1} vs defense: {max_def1}")

            print(f"\nAttacking troups: {troup_att} \nDefending troups: {troup_def}\n")
            
            # Clears the screen (similar to C++ system commands)
            #time.sleep(0.25)
            #os.system('cls' if os.name == 'nt' else 'clear')

        print("##########################################\n")
        print(f"Attacking remaining: {troup_att}")
        print(f"Defending remaining: {troup_def}\n")

        print(f"Attacking units lost: {troup_att_old - troup_att}")
        print(f"Defending units lost: {troup_def_old - troup_def}\n")

        lost_total_att += troup_att_old - troup_att
        lost_total_def += troup_def_old - troup_def

        print(f"Total troups lost: Att: {lost_total_att} Def: {lost_total_def}")
        print("##########################################\n\n")

        # Restarting the game with new inputs
        troup_att = int(input("Troup attack amount: "))
        

if __name__ == "__main__":
    main()
