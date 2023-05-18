    if(TI == 0){
        if(SI != 0){
            switch(SI){
                case 1:
                    read(RA);
                    break;
                case 2:
                    write(RA);
                    break;
                case 3:
                    Terminate(0);
                    breakFlag = true;
                    break;
                default:
                    cout<<"Error with SI."<<endl;
            }
            SI = 0;
        }
        else if(PI != 0){
            switch(PI){
                case 1:
                    Terminate(4);
                    breakFlag = true;
                    break;
                case 2:
                    Terminate(5);
                    breakFlag = true;
                    break;
                case 3:
                    PI = 0;
                    //Page Fault checking
                    char temp[3];
                    memset(temp,'\0',3);
                    memcpy(temp, IR, 2);

                    if(!strcmp(temp,"GD") || !strcmp(temp,"SR")){
                        int m;
                        do{
                            m = allocate();
                        }while(M[m*10][0]!='\0');

                        int currPTR = PTR;
                        while(M[currPTR][0]!='*')
                            currPTR++;

                        itoa(m, M[currPTR], 10);

                        cout << "Valid Page Fault, page frame = " << m << endl;
                        cout << "PTR = " << PTR << endl;
                        for(int i=0; i<300; i++){
                            cout<<"M["<<i<<"] :";
                            for(int j=0 ; j<4; j++){
                                cout<<M[i][j];
                            }
                            cout<<endl;
                        }
                        cout<<endl;

                        if(pcb.TTC+1 > pcb.TTL){
                            TI = 2;
                            PI = 3;
                            mos();
                            break;
                        }
                        pcb.TTC++;
                        return 1;
                    }
                    else if(!strcmp(temp,"PD") || !strcmp(temp,"LR") || !strcmp(temp,"H") || !strcmp(temp,"CR") || !strcmp(temp,"BT")){
                        Terminate(6);
                        breakFlag = true;

                        if(pcb.TTC+1 > pcb.TTL){
                            TI = 2;
                            PI = 3;
                            mos();
                            break;
                        }
                        //pcb.TTC++;
                    }
                    else{
                        PI = 1;
                        mos();
                    }
                    return 0;
                default:
                    cout<<"Error with PI."<<endl;
            }
            PI = 0;
        }
    }
    else{
        if(SI != 0){
            switch(SI){
                case 1:
                    Terminate(3);
                    breakFlag = true;
                    break;
                case 2:
                    write(RA);
                    if(!breakFlag) Terminate(3);
                    break;
                case 3:
                    Terminate(0);
                    breakFlag = true;
                    break;
                default:
                    cout<<"Error with SI."<<endl;
            }
            SI = 0;
        }
        else if(PI != 0){
            switch(PI){
                case 1:
                    Terminate(3,4);
                    breakFlag = true;
                    break;
                case 2:
                    Terminate(3,5);
                    breakFlag = true;
                    break;
                case 3:
                    Terminate(3);
                    breakFlag = true;
                    break;
                default:
                    cout<<"Error with PI."<<endl;
            }
            PI = 0;
        }
    }

    return 0;