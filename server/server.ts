// server.ts - Simple TCP server
import * as net from 'net';

const server = net.createServer((socket) => {
    console.log('Client connected!');
    
    socket.on('data', (data) => {
        console.log('Received:', data.toString());
        socket.write('Hello from TypeScript server!');
    });
});

server.listen(8080, () => {
    console.log('Server listening on port 8080');
});
