use rand::random_range;

fn main()
{
    let mut counter: i32 = 0;
    let mut iterator: i32 = 0;
    
    let mut random_number: i32;
    
    while iterator != 100
    {
        random_number = random_range(-1000..1001);
        if i32::abs(random_number) <= 100
        {
            counter += 1;
        }
        iterator += 1;
    }
    
    println!("{}", counter);
}
