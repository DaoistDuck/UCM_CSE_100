int feb(int k, int *r){
    if(k == 1 || k == 2){
        return 1;
    }
    if(r[k] >= 0){
        return r[k];
    }
    int q = feb(k - 1, r) + feb(k - 2, r);
    r[k] = q;
    return q;
}