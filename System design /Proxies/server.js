// Actual server 
// nginx.conf which is a web server that can be used as a web proxy is the proxy that alters the header of the packet
const express=require('express');

const app=express();

app.listen(3000,()=>console.log('listening on port 3000'));
app.get('/hello',(req,res)=>{

    console.log(req.headers);
    res.send('Hello\n');
});