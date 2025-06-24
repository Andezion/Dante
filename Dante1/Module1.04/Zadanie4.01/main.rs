fn main()
{
    let array:[i32; 10] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
    
    println!("{:?}", array);
    
    for i in &array
    {
        print!("{} ", i);    
    }
    
    return;
}
