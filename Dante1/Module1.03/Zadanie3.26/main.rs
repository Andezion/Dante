use rand::random_range;

fn main()
{
    let mut array:[i32; 10] = [0; 10];
    for i in 0 .. 10
    {
        array[i] = random_range(10 .. 21);
        print!("{} ", array[i]);
    }
    
    return;
}
