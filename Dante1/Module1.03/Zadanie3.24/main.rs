use rand::random_range;

fn main()
{
    let number: i32 = random_range(0..100);
    println!("Number is: {}", number);
    
    let mut array:[i32; 10] = [0; 10];
    for i in 0 .. 10
    {
        array[i] = random_range(0 .. 10);
        print!("{} ", array[i]);
    }
    
    return;
}
