#include<iostream>
#include<iomanip>

using namespace std;

// class MissionariesGame
class MissionariesGame{
public:
    int counto, i; // counto is the number of times the game is played
    char left[6], right[6]; // left and right arrays contains the number of missionaries and cannibals on either // side of the boat
    int m_num, c_num; // m_num - number of missionaries, c_num - number of cannibals
    bool side;
    int ml_count, cl_count; // number of missionaries and cannibals on left side
    int mr_count, cr_count; // // number of missionaries and cannibals on right side

// default constructor
    MissionariesGame(){
        counto = 1;
// initialize the ml_count and cl_count to 3 represent that 3 missionaries and cannibals are present on left side.
        ml_count = cl_count = 3;
// no missionaries and cannibals are present on right side
        mr_count = cr_count = 0;
// set side to false
        side = false;
// set the left and right arrays
        for (i = 0; i<3; i++){
            left[i] = 'M';
            left[i + 3] = 'C';
            right[i] = ' ';
            right[i + 3] = ' ';
        }
    }

// get the user input
    void get(){
        start:
        cout << "\nEnter no.of missionaries: ";
        cin >> m_num;
        cout << "\nEnter no.of cannibals: ";
        cin >> c_num;
        if (m_num>3 || c_num>3 || m_num<0 || c_num<0)
            goto start;
        else if ((m_num + c_num)>2 || (m_num + c_num == 0))
            goto start;
    }

// display the number of missionaries and cannibals on either side of the boat
    void displaymc(){
        cout << "\nleft side\tright side\n";
        for (i = 0; i<3; i++)
            cout << left[i] << " ";
        cout << "\t\t";

        for (i = 0; i<3; i++)
            cout << right[i] << " ";
        cout << endl;

        for (i = 3; i<6; i++)
            cout << left[i] << " ";
        cout << "\t\t";

        for (i = 3; i<6; i++)
            cout << right[i] << " ";
        cout << endl;

        if (counto % 2 == 0){
            side = true;
            cout << "\nBoat on right side of river\n";
        } else{
            side = false;
            cout << "\nBoat on left side of river\n";
        }
    }


// this method handles when the boat moves from left to right
    void boat_lr(){
        for (i = 0; i<m_num; i++){
            if (left[0] == 'M'){
                left[0] = ' ';
                right[0] = 'M';
                ml_count -= 1;
                mr_count += 1;
            } else if (left[1] == 'M'){
                left[1] = ' ';
                right[1] = 'M';
                ml_count -= 1;
                mr_count += 1;
            } else if (left[2] == 'M'){
                left[2] = ' ';
                right[2] = 'M';
                ml_count -= 1;
                mr_count += 1;
            }
        }

        for (i = 0; i<c_num; i++){
            if (left[3] == 'C'){
                left[3] = ' ';
                right[3] = 'C';
                cl_count -= 1;
                cr_count += 1;
            } else if (left[4] == 'C'){
                left[4] = ' ';
                right[4] = 'C';
                cl_count -= 1;
                cr_count += 1;
            } else if (left[5] == 'C'){
                left[5] = ' ';
                right[5] = 'C';
                cl_count -= 1;
                cr_count += 1;
            }
        }
    }


// this method handles when the boat moves from right to left
    void boat_rl(){
        for (i = 0; i<m_num; i++){
            if (right[0] == 'M'){
                right[0] = ' ';
                left[0] = 'M';
                ml_count += 1;
                mr_count -= 1;
            } else if (right[1] == 'M'){
                right[1] = ' ';
                left[1] = 'M';
                ml_count += 1;
                mr_count -= 1;
            } else if (right[2] == 'M'){
                right[2] = ' ';
                left[2] = 'M';
                ml_count += 1;
                mr_count -= 1;
            }
        }

        for (i = 0; i<c_num; i++){
            if (right[3] == 'C'){
                right[3] = ' ';
                left[3] = 'C';
                cl_count += 1;
                cr_count -= 1;
            } else if (right[4] == 'C'){
                right[4] = ' ';
                left[4] = 'C';
                cl_count += 1;
                cr_count -= 1;
            } else if (right[5] == 'C'){
                right[5] = ' ';
                left[5] = 'C';
                cl_count += 1;
                cr_count -= 1;
            }
        }
    }
};

int main(){
// create an instance of the MissionariesGame
    MissionariesGame g;


// while loop to continue execution as long as the user has not won/lost
    while (true){
        if (g.ml_count<g.cl_count && g.ml_count>0 || g.mr_count<g.cr_count && g.mr_count>0){
            cout << "\n\nYOU LOST!\n";
            break;
        } else if (g.cr_count == g.mr_count && g.cr_count == 3 && g.mr_count == 3){
            cout << "\n\nYOU WON!!\n";
            break;
        } else{
            g.displaymc();
            g.get();

            if (g.side == false)
                g.boat_lr();
            else
                g.boat_rl();
        }

        g.counto++;
    }

    return 0;
}