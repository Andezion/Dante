use rand::random_range;

fn main()
{
    let mut sum: i32 = 0;
    let mut array:[i32; 100] = [0; 100];
    for i in 0 .. 100
    {
        array[i] = random_range(10 .. 21);
        sum = sum + array[i];
    }
    
    println!("Sum is: {}", sum);
    
    return;
}
