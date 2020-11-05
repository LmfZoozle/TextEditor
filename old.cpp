
    if (argc > 2)
    {
        if (argv[2]=="-r"){
            cout << NAME<<" ReadOnly with" << argv[1]<<endl;
            mode=Read;
        }else if(argv[2]=="-w"){
            cout <<NAME<< " with" << argv[1]<<endl;
            mode=Write;
        }
    }
    else if (argc > 1)
    {
        cout <<NAME<< " with" << argv[1]<<endl;
        mode=Write;
    }
    else
    {
        cout <<NAME<< " new"<< endl;
        mode=Write;
    }
