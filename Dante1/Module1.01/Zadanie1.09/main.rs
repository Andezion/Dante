fn main()
{
    let number_one: i32 = 5;
    let number_two: i32 = 4;
    
    println!("The value of number_one is: {}", number_one);
    println!("The value of number_two is: {}", number_two);
    
    println!("The sum is: {}", number_one + number_two);
    println!("The difference is: {}", number_two - number_one);
    println!("The multiplication is: {}", number_two * number_one);
    
    println!("The division is: {:.2}", number_one as f32 / number_two as f32);
    
    return;
}
