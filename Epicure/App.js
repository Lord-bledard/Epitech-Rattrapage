import React, { useEffect } from 'react';
import { StyleSheet, Text, Button, View } from 'react-native';
import * as WebBrowser from 'expo-web-browser';
import { makeRedirectUri, useAuthRequest, ResponseType } from 'expo-auth-session';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import NavBar from './Components/NavBar';
import * as Constant from './Constant';

WebBrowser.maybeCompleteAuthSession();

function LogInScreen({ navigation }) {
    const [request, response, promptAsync] = useAuthRequest(
        {
        responseType: ResponseType.Token,
        clientId: Constant.CLIENT_ID,
        redirectUri: makeRedirectUri({
            useProxy: false
        }),
        },
        Constant.DISCOVERY
    );

    React.useEffect(() => {
        if (response?.type === 'success') {
            Constant.ACCESS_TOKEN = response.params.access_token;
            navigation.navigate('Home');
        }
    }, [response]);

    return (
        <View style={styles.container}>
            <Text style={styles.title}>Epicture</Text>

            <Button
                style={styles.buttonmenu}
                disabled={!request}
                title="Sign in"
                onPress={() => promptAsync()}
            />
        </View>
    );
}

function HomeScreen({ navigation }) {
    return (
        <View style={styles.mainContainer}>
            <NavBar />
        </View>
    );
}

const Stack = createStackNavigator();

export default function App() {
    return (
        <NavigationContainer>
            <Stack.Navigator initialRouteName='LogIn'>
                <Stack.Screen name='LogIn' component={LogInScreen} />
                <Stack.Screen name='Home' component={HomeScreen} />
            </Stack.Navigator>
        </NavigationContainer>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: '#eee',
        alignItems: 'center',
        justifyContent: 'center',
    },
    title: {
      color: '#444',
      fontSize: 36,
      marginBottom: 10,
    },
    buttonmenu: {
        backgroundColor: '#005ca4',
        padding: 10,
        borderRadius: 5,
    },
    mainContainer: {
        flex: 1,
    },
});
