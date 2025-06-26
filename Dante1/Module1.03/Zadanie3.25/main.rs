use rand::random_range;

fn main()
{
    let number: i32 = random_range(30..41);
    println!("Number is: {}", number);
    
    return;
}
