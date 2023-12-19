use std::env;
use std::fs::File;
use std::io::{self, Read, Write, Seek, SeekFrom};

fn main() -> io::Result<()> {
    let args: Vec<String> = env::args().collect();

    if args.len() != 3 {
        eprintln!("Usage: strip_rsa_dec <src binary> <target binary>");
        std::process::exit(1);
    }

    let src_path = &args[1];
    let dst_path = &args[2];

    let mut src_file = File::open(src_path)?;
    let mut dst_file = File::create(dst_path)?;

    let file_length = src_file.seek(SeekFrom::End(0))?;
    src_file.seek(SeekFrom::Start(file_length - 32))?;

    let mut buffer = [0u8; 32];
    src_file.read_exact(&mut buffer)?;
    dst_file.write_all(&buffer)?;

    Ok(())
}
