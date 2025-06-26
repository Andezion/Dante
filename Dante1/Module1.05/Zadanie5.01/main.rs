fn main()
{
    let mut data:[u8; 26] = [0; 26];
    let mut number: u8 = 65;
    
    for i in 0..26
    {
        data[i] = number;
        number += 1;
    }
    
    for i in 0..26
    {
        println!("{} {} {}", data[i], data[i] as char, (data[i] + 32) as char);
    }
}
