import React, { useEffect, useState } from 'react';
import { Button, StyleSheet, Text, View } from 'react-native';
import FlexImage from 'react-native-flex-image';
import * as Constant from '../Constant';

export default function ImgurPost({ post }) {
    const [fav_text, setFavText] = useState('');
    const [fav_color, setFavColor] = useState('');

    useEffect(() => {
        if (post.favorite) {
            setFavText('Enlever des favoris');
            setFavColor('lawngreen');
        } else {
            setFavText('Ajouter aux favoris');
            setFavColor('grey');
        }
    });

    const onPress = () => {
        const url = `https://api.imgur.com/3/image/${post.cover}/favorite`;
        
        const myHeaders = new Headers();
        myHeaders.append('Authorization', `Bearer ${Constant.ACCESS_TOKEN}`);

        const requestOptions = {
            methods: 'POST',
            headers: myHeaders,
            redirect: 'follow',
        };

        return fetch(url, requestOptions)
        .then(res => res.json())
        .then(json => {
            console.log(json)
        })
        .catch(err => console.log('ERROR', err));
    };

    return (
        <View style={styles.post}>
            <Text style={styles.title}>{post.title}</Text>
            <FlexImage
                source={{uri: `${post.images[0].link}`}}
                style={styles.image}
            />
            <Button
                title={fav_text}
                color={fav_color}
                onPress={onPress}
            />
        </View>
    );
}

const styles = StyleSheet.create({
    post: {
        backgroundColor: 'navy',
        borderRadius: 10,
        marginTop: 10,
        padding: 5,
    },
    title: {
        color: 'white',
        fontSize: 18,
        fontWeight: 'bold',
        flexWrap: 'wrap',
        margin: 5,
    },
    image: {
        marginLeft: 5,
        marginBottom: 5,
    },
});
