    vector<int> arr = {1,2,3,4,5};
    int sum = 0;

    for(auto i = arr.cbegin(); i < arr.cend(); i++){
        sum+=*i;
    }
    cout << "odd sum of arr : " << sum << endl;