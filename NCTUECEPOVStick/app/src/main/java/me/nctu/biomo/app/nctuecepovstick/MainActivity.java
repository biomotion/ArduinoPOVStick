package me.nctu.biomo.app.nctuecepovstick;

import java.util.Set;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.support.v7.app.AppCompatActivity;
import android.content.Intent;
import android.widget.Spinner;
import android.widget.ArrayAdapter;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
    BluetoothAdapter mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
    Spinner devices = (Spinner)findViewById(R.id.spinner1);
    ArrayAdapter<String> adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if (!mBluetoothAdapter.isEnabled()) {
            Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableBtIntent, 0);
        }
        findViewById(R.id.spinner1);
       Set<BluetoothDevice> deviceSet = mBluetoothAdapter.getBondedDevices();

       String arr[] = new String[deviceSet.size()];
       int i=0;
       for(BluetoothDevice d : deviceSet)
           arr[i++] = d.getName();
        adapter = new ArrayAdapter(this, android.R.layout.simple_spinner_dropdown_item, arr);
        devices.setAdapter(adapter);

    }
}
