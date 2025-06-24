fn main()
{
    let mut array:[usize; 11] = [0; 11];
    
    for i in 0..11
    {
        array[i] = i;
    }
    
    for i in 0..11
    {
        print!("{} ", array[i]);
    }
    
    return;
}
