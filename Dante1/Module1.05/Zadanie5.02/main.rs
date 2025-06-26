fn main()
{
    let array:[char; 13] = ['T','o',' ','j','e','s','t',' ','t','e','k','s','t'];
    
    for i in 0..array.len()
    {
        let letter:char = array[i];
        let number: u8 = letter as u8;
        
        println!("{} {}", number, letter);
    }
}
